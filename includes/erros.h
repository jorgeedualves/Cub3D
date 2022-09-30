/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:52:59 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/30 16:38:21 by joeduard         ###   ########.fr       */
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
# define E_MLX "Error\nMLX_INIT FAILURE\n"
# define E_MLXWIN "Error\nMLX_WIN FAILURE\n"
# define E_MLXIMG "Error\nMLX_IMG_FAILURE\n"
# define E_MLX_ADDR "Error\nMLX_ADDR_FAILURE\n"

#endif