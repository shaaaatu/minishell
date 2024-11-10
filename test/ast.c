#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASTNode {
    char *value;                  // コマンドや演算子
    struct ASTNode *left;         // 左の子ノード
    struct ASTNode *right;        // 右の子ノード
} ASTNode;

// ノードの作成関数
ASTNode* createNode(char *value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->value = strdup(value);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 簡易AST構築関数（再帰を用いた構築例）
// 優先順位の低い演算子から順に検索してASTを構築
// 優先順位の低い演算子から順に検索してASTを構築
ASTNode* buildAST(char *tokens[], int start, int end) {
	printf("start: %s, end: %s\n", tokens[start], tokens[end]);
    if (start > end) {
        return NULL;
    }
    
    // 基本ケース：単一のコマンドが残った場合
    if (start == end) {
        return createNode(tokens[start]);
    }

    // 優先順位の低い演算子から順に検索
    const char *operators[] = {"||", "&&", "|", ">", "<", ">>", "<<"};
    int numOperators = sizeof(operators) / sizeof(operators[0]);

    for (int opIndex = 0; opIndex < numOperators; opIndex++) {
        int operatorPos = -1;

        // 優先順位に従って右から左へ検索
        for (int i = end; i >= start; i--) {
            if (strcmp(tokens[i], operators[opIndex]) == 0) {
				ASTNode *node = createNode(tokens[i]);
				node->left = buildAST(tokens, start, i - 1);
				node->right = buildAST(tokens, i + 1, end);
				return node;
            }
        }
    }
    // 演算子が見つからない場合、単一のコマンドとしてノードを作成
    return createNode(tokens[start]);
}

void printAST(ASTNode *node, int level) {
    if (node == NULL) return;

    // 右の子ノードを先に表示する
    if (node->right) {
        printAST(node->right, level + 1);
    }

    // インデントを表示
    for (int i = 0; i < level; i++) {
        printf("        ");
    }

    // 現在のノードの値を表示
    printf("%s\n", node->value);

    // 左の子ノードを表示
    if (node->left) {
        printAST(node->left, level + 1);
    }
}

int main() {
    // コマンドラインをトークン化したものと仮定
    char *tokens[] = {"cat", "<", "input.txt", "|", "grep", ".c", "&&", "echo", "Success", "|", "sort", ">", "output.txt", "||", "echo", "Failure"};
    int numTokens = sizeof(tokens) / sizeof(tokens[0]);

    // ASTを構築
    ASTNode *root = buildAST(tokens, 0, numTokens - 1);

    // デモ用：構築したASTのルートを表示
	printAST(root, 0);
    return 0;
}
