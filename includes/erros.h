/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:52:59 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/29 18:52:27 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRO_H
#define ERRO_H

// Criar MACRO DE ERROS

//Validations
# define E_RESINVAL "Error\nResolution below minimum of 1024x768\n"
# define E_NOMAP "error\nThe map was not specified!\n"
# define E_MANYARG "error\nThere are many arguments\n"
# define E_MAPINVAL "Error\nThis map is not valid!\n"

// MLX
# define E_MLXFAIL "Error\nMLX_INIT FAILURE\n"

#endif