#ifndef EDITOR_H
#define EDITOR_H

#include <string>
#include <stack>

class Editor {
public:
    Editor();
    
    void Type(char c);
    void ShiftLeft();
    void ShiftRight();
    void Backspace();
    void Undo();
    void Redo();
    
    const std::string &GetText() const;
    
private:
    std::string textBuffer;
    int cursorPosition;
    
    std::stack<std::string> actionsHistory;
    std::stack<std::string> undoneActionsHistory;
    
    void saveAction();
};

#endif // EDITOR_H