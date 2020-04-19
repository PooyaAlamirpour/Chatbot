#include "graphedge.h"
#include "graphnode.h"
#include "chatlogic.h"
#include <iostream>

GraphNode::GraphNode(int id) {
    _id = id;
}

GraphNode::~GraphNode() {
    //// STUDENT CODE
    ////

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) {
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge) {
    _childEdges.push_back(std::unique_ptr<GraphEdge>(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot &&chatBot) {
    _chatBot = std::move(chatBot);
    _chatBot.GetChatLogicHandle()->SetChatbotHandle(&_chatBot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}