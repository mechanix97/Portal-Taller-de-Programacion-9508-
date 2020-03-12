#ifndef EDITOR_EXCEPCION_H
#define EDITOR_EXCEPCION_H

#include <string>

class ExcepcionEditor : public std::exception {
protected:
    std::string msj;

public:
    ExcepcionEditor(char const *mensaje);
    virtual ~ExcepcionEditor();
    const char *what() const throw();
};

#endif // EDITOR_EXCEPCION_H
