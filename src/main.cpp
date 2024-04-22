#include "editor.h"
#include <iostream>

int main() {
    Editor textEditor;
    
    textEditor.Type('H');
    textEditor.Type('e');
    textEditor.Type('l');
    textEditor.Type('l');
    textEditor.Type('o');
    std::cout << textEditor.GetText() << std::endl;
    
    textEditor.Undo();
    std::cout << textEditor.GetText() << std::endl;
    
    textEditor.Redo();
    std::cout << textEditor.GetText() << std::endl;
    
    textEditor.Backspace();
    std::cout << textEditor.GetText() << std::endl; 
    
    textEditor.ShiftLeft();
    textEditor.ShiftLeft();
    textEditor.Type('x');
    std::cout << textEditor.GetText() << std::endl; 

    textEditor.ShiftRight();
    textEditor.Type(' ');
    std::cout << textEditor.GetText() << std::endl; 
    
    return 0;
}
