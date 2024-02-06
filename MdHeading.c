//
// Created by DELL on 2024/2/5.
//

#include "AstNodeDefinition.h"

bool isHeading(AstNode* node){
    return node->type == AST_NODE_TYPE_HEADING;
}

AstNode* createHeading(int level, AstNode* content){
    AstNode* node = (AstNode*)malloc(sizeof(AstNode));
    node->type = AST_NODE_TYPE_HEADING;
    node->id = ++NodeCount;
    node->heading = (MdHeading*)malloc(sizeof(MdHeading));
    node->heading->level = level;
    node->heading->content = content;
    return node;
}

void destroyHeading(AstNode* node){
    destroyNode(node->heading->content);
    free(node->heading);
    free(node);
}

void heading2Mermaid(AstNode* node){
    printf("%d[H%d]--content-->%d\n",node->id,node->heading->level,node->heading->content->id);
    node2Mermaid(node->heading->content);
}

void heading2Html(AstNode* node){
    printf("<h%d>",node->heading->level);
    node2Html(node->heading->content);
    printf("</h%d>",node->heading->level);
}