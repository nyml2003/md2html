//
// Created by DELL on 2024/2/5.
//

#include "AstNodeDefinition.h"
bool isDocument(AstNode* node){
    return node->type == AST_NODE_TYPE_DOCUMENT;
}

AstNode* createDocument(){
    AstNode* node = (AstNode*)malloc(sizeof(AstNode));
    node->type = AST_NODE_TYPE_DOCUMENT;
    node->id = ++NodeCount;
    node->document = (MdDocument*)malloc(sizeof(MdDocument));
    node->document->children_count = 0;
    node->document->children = NULL;
    return node;
}

void destroyDocument(AstNode* node){
    for (int i = 0; i < node->document->children_count; i++){
        destroyNode(node->document->children[i]);
    }
    free(node->document->children);
    free(node->document);
    free(node);
}

void document2Mermaid(AstNode* node){
    printf("%d[Doucment,count:%d]\n",node->id,node->document->children_count);
    for (int i = 0; i < node->document->children_count; i++){
        printf("%d--line%d-->%d\n",node->id,i,node->document->children[i]->id);
        node2Mermaid(node->document->children[i]);
    }
}

AstNode* documentAddChild(AstNode* document, AstNode* child){
    if (child == NULL){
        return document;
    }
    MdDocument *doc = document->document;
    doc->children = (AstNode**)realloc(doc->children, sizeof(AstNode*) * (doc->children_count + 1));
    doc->children[doc->children_count++] = child;
    return document;
}

void document2Html(AstNode* node){
    for (int i = 0; i < node->document->children_count; i++){
        node2Html(node->document->children[i]);
    }
}