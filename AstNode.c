//
// Created by DELL on 2024/2/5.
//

#include "AstNodeDefinition.h"

int NodeCount = 0;

void compile(AstNode *document) {
    NodeCount = 0;
//    printf("```mermaid\n");
//    printf("graph TD\n");
//    node2Mermaid(document);
//    printf("```\n");
    printf("<!DOCTYPE html>\n");
    printf("<html>\n");
    printf("<head>\n");
    printf("<title>Markdown</title>\n");
    printf("</head>\n");
    printf("<body>\n");
    node2Html(document);
    printf("</body>\n");
    printf("</html>\n");
    destroyNode(document);
    exit(0);
}

void destroyNode(AstNode *node) {
    switch (node->type) {
        case AST_NODE_TYPE_DOCUMENT:
            destroyDocument(node);
            break;
        case AST_NODE_TYPE_TEXT:
            destroyText(node);
            break;
        case AST_NODE_TYPE_HEADING:
            destroyHeading(node);
            break;
        case AST_NODE_TYPE_PARAGRAPH:
            destroyParagraph(node);
            break;
    }
}

void node2Mermaid(AstNode *node) {

    switch (node->type) {
        case AST_NODE_TYPE_DOCUMENT:
            document2Mermaid(node);
            break;
        case AST_NODE_TYPE_TEXT:
            text2Mermaid(node);
            break;
        case AST_NODE_TYPE_HEADING:
            heading2Mermaid(node);
            break;
        case AST_NODE_TYPE_PARAGRAPH:
            paragraph2Mermaid(node);
            break;
    }
}

void node2Html(AstNode *node) {
    switch (node->type) {
        case AST_NODE_TYPE_DOCUMENT:
            document2Html(node);
            break;
        case AST_NODE_TYPE_TEXT:
            text2Html(node);
            break;
        case AST_NODE_TYPE_HEADING:
            heading2Html(node);
            break;
        case AST_NODE_TYPE_PARAGRAPH:
            paragraph2Html(node);
            break;
    }
}