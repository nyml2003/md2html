//
// Created by DELL on 2024/2/5.
//

#ifndef MD2HTML_ASTNODEDEFINITION_H
#define MD2HTML_ASTNODEDEFINITION_H
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
/*
 * AST节点定义
 */
typedef struct _AstNode AstNode;
typedef struct _MdDocument MdDocument;
typedef struct _MdText MdText;
typedef struct _MdHeading MdHeading;
typedef struct _MdParagraph MdParagraph;
typedef enum {
    AST_NODE_TYPE_DOCUMENT,
    AST_NODE_TYPE_TEXT,
    AST_NODE_TYPE_HEADING,
    AST_NODE_TYPE_PARAGRAPH,
} AstNodeType;
typedef struct _AstNode{
    AstNodeType type;
    int id;
    union {
        MdDocument* document;
        MdText* text;
        MdHeading* heading;
        MdParagraph* paragraph;
    };
} AstNode;
void destroyNode(AstNode* node);
void node2Mermaid(AstNode* node);
void node2Html(AstNode* node);
void compile(AstNode* document);
extern int NodeCount;
/*
 * document节点
 */
typedef struct _MdDocument{
    int children_count;
    AstNode** children;
} MdDocument;
bool isDocument(AstNode* node);
AstNode* createDocument();
void destroyDocument(AstNode* node);
void document2Mermaid(AstNode* node);
void document2Html(AstNode* node);
AstNode* documentAddChild(AstNode* document, AstNode* child);

/*
 * text节点
 */
typedef struct _MdText{
    char* content;
    int length;
} MdText;
bool isText(AstNode* node);
AstNode* createText(char* content);
void destroyText(AstNode* node);
void text2Mermaid(AstNode* node);
void text2Html(AstNode* node);
/*
 * heading节点
 */
typedef struct _MdHeading{
    int level;
    AstNode* content;
} MdHeading;
bool isHeading(AstNode* node);
AstNode* createHeading(int level, AstNode* content);
void destroyHeading(AstNode* node);
void heading2Mermaid(AstNode* node);
void heading2Html(AstNode* node);

/*
 * paragraph节点
 */
typedef struct _MdParagraph{
    AstNode* content;
} MdParagraph;
bool isParagraph(AstNode* node);
AstNode* createParagraph(AstNode* content);
void destroyParagraph(AstNode* node);
void paragraph2Mermaid(AstNode* node);
void paragraph2Html(AstNode* node);

#endif //MD2HTML_ASTNODEDEFINITION_H
