//
// Created by DELL on 2024/2/5.
//
#include "AstNodeDefinition.h"

bool isText(AstNode* node){
    return node->type == AST_NODE_TYPE_TEXT;
}

AstNode* createText(char* content){
    AstNode* node = (AstNode*)malloc(sizeof(AstNode));
    node->type = AST_NODE_TYPE_TEXT;
    node->id = ++NodeCount;
    node->text = (MdText*)malloc(sizeof(MdText));
    node->text->length = strlen(content);
    node->text->content = (char*)malloc(node->text->length);
    strcpy(node->text->content,content);
    return node;
}

void destroyText(AstNode* node){
    free(node->text->content);
    free(node->text);
    free(node);
}

void text2Mermaid(AstNode* node){
    printf("%d[Text:%s]\n",node->id,node->text->content);
}

void text2Html(AstNode* node){
    printf("%s",node->text->content);
}