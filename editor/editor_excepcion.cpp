#include "editor_excepcion.h"

ExcepcionEditor::ExcepcionEditor(char const *mensaje) {
    this->msj = mensaje;
}

ExcepcionEditor::~ExcepcionEditor() {
}

const char *ExcepcionEditor::what() const throw() {
    return this->msj.c_str();
}
