//
// Created by DELL on 2024/2/6.
//
#include "AstNodeDefinition.h"

bool isParagraph(AstNode* node){
    return node->type == AST_NODE_TYPE_PARAGRAPH;
}

AstNode* createParagraph(AstNode* content){
    AstNode* node = (AstNode*)malloc(sizeof(AstNode));
    node->type = AST_NODE_TYPE_PARAGRAPH;
    node->id = ++NodeCount;
    node->paragraph = (MdParagraph*)malloc(sizeof(MdParagraph));
    node->paragraph->content = content;
    return node;
}

void destroyParagraph(AstNode* node){
    destroyNode(node->paragraph->content);
    free(node->paragraph);
    free(node);
}

void paragraph2Mermaid(AstNode* node){
    printf("%d[Paragraph]-->%d\n", node->id, node->paragraph->content->id);
    node2Mermaid(node->paragraph->content);
}

void paragraph2Html(AstNode* node){
    printf("<p>");
    node2Html(node->paragraph->content);
    printf("</p>");
}