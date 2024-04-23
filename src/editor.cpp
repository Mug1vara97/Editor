#include "editor.h"

Editor::Editor() : cursorPosition(0) {
    textBuffer = "";
}

void Editor::Type(char c) {
    actionsHistory.push(textBuffer);
    undoneActionsHistory = std::stack<std::string>();
    
    textBuffer.insert(cursorPosition, 1, c);
    cursorPosition++;
}

void Editor::ShiftLeft() {
    if (cursorPosition > 0) {
        cursorPosition--;
    }
}

void Editor::ShiftRight() {
    if (cursorPosition < textBuffer.size()) {
        cursorPosition++;
    }
}

void Editor::Backspace() {
    if (cursorPosition > 0) {
        actionsHistory.push(textBuffer);
        undoneActionsHistory = std::stack<std::string>();
        
        textBuffer.erase(cursorPosition - 1, 1);
        cursorPosition--;
    }
}

void Editor::Undo() {
    if (!actionsHistory.empty()) {
        undoneActionsHistory.push(textBuffer);
        textBuffer = actionsHistory.top();
        actionsHistory.pop();
    }
}

void Editor::Redo() {
    if (!undoneActionsHistory.empty()) {
        actionsHistory.push(textBuffer);
        textBuffer = undoneActionsHistory.top();
        undoneActionsHistory.pop();
    }
}

void Editor::saveAction() {
    actionsHistory.push(textBuffer);
    undoneActionsHistory = std::stack<std::string>();
}

const std::string &Editor::GetText() const {
    return textBuffer;
}
