/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:48:24 by yabarhda          #+#    #+#             */
/*   Updated: 2026/06/29 12:42:39 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137)
{
	target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

void ShrubberyCreationForm::doAction() const
{
  std::ofstream tree((target + "_shrubbery").c_str());
	if (!tree.is_open()) {
		std::cerr << "Error of some sort, couldn't create/open the file, probably of low space" << std::endl;
		return ;
	}
    const char *art =
    "                                                         .\n"
    "                                              .         ;  \n"
    "                 .              .              ;$     ;;   \n"
    "                   ,           ,                :;$  $;   \n"
    "                    :         ;                   :;$;*     .,   \n"
    "           ,.        $;     $;            ;        $;*    ,;\n"
    "             ;       ;$;  $$;        ,     $;    ;$;    ,$*\n"
    "              $;       $;$;      ,  ;       $;  ;$;   ,$;* \n"
    "               ;$;      $;        ;$;        $ ;$;  ,$;*\n"
    "                -$;.     ;$;     $;*         -;$$;.$;*\n"
    "                 -:;$.    ;$$. $@;        $; ;@$;$*\n"
    "                    -:$;.  :;bd$;          $;@$;*\n"
    "                      -@$:.  :;$.         ;@@$;*   \n"
    "                        -@$.  -;@$.      ;@@$;         \n"
    "                          -@$$. -@$$    ;@@$;        \n"
    "                            ;@$. :@$$  $@@$;       \n"
    "                              $@bd$$$bd$$:;     \n"
    "                                #@$$$$$:;;\n"
    "                                $@@$$$::;\n"
    "                                $@@@$(o);  . *         \n"
    "                                $@@@o$;:(.,*         \n"
    "                            -.. $@@@o$::;         \n"
    "                               -)@@@o$::;         \n"
    "                                $@@(o)::;        \n"
    "                               .$@@@@$::;         \n"
    "                               ;$@@@@$::;.          \n"
    "                              ;$@@@@$$:;;;. \n"
    "                          ...;$@@@@@$$:;;;;,..\n";
    tree << art;
    tree.close();
}
