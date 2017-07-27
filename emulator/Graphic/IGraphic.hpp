#ifndef			IGRAPHIC_H
# define		IGRAPHIC_H

# include		<iostream>
# include		"Standards.hpp"
# include		"typedef.hpp"

namespace retromania
{

class			IGraphic
{
  public:
    virtual		~IGraphic() {}

    virtual std::string const	&getName() const = 0;
    virtual InputType	getInput() const = 0;
    virtual void 	createWindow() = 0;
    virtual void 	quitWindow() = 0;
    virtual void	setConfig(conf_t const *config) = 0;
    virtual void	blitText(std::string const &text,
				 retromania::pos_t const &pos,
				 int const fontSize,
				 ColorType const color) = 0;
    virtual void	display(const Sptr_t<map_t> map = nullptr) = 0;
};

}

#endif			/* !IGRAPHIC */
