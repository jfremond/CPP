/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:36:49 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/29 16:36:46 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string const		_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
		virtual ~ShrubberyCreationForm();
		virtual void			execute(Bureaucrat const &executor) const;
};

#endif
