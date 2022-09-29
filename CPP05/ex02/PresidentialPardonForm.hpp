/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:30:39 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/29 16:36:18 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string const		_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);
		virtual ~PresidentialPardonForm();
		virtual void		execute(Bureaucrat const &executor) const;
};

#endif
