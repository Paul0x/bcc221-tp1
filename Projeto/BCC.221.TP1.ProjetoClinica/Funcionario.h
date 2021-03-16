/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funcionario.h
 * Author: paulo
 *
 * Created on March 9, 2021, 7:55 AM
 */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <vector>
#include "RegistroPonto.h"
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include "Usuario.h"
#include <functional>
#include <algorithm>
#include <memory>

class Funcionario : public Usuario {
public:
    Funcionario();
    Funcionario(const Funcionario& orig);
    virtual ~Funcionario();
    void setFolhaPonto(vector<std::shared_ptr<RegistroPonto> > folhaPonto);
    vector<std::shared_ptr<RegistroPonto> > getFolhaPonto() const;
    void adicionarRegistroPonto();
    void mostrarFolhaPonto();
    void sortFolhaPonto();
private:
    vector<std::shared_ptr<RegistroPonto>> folhaPonto;



};

#endif /* FUNCIONARIO_H */

