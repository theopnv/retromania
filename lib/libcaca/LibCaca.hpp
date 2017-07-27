#ifndef			LIBCACA_H
# define		LIBCACA_H

# include 		<map>
# include		<caca.h>
# include "AGraphic.hpp"
# include		"IGraphic.hpp"

namespace retromania
{

class			LibCaca : public AGraphic
{
  private:
    typedef std::map<ColorType, uint8_t>		colorTab_t;
    typedef std::map<int, InputType>			inputTab_t;

    colorTab_t	colorTab;
    inputTab_t _inputTab;
    static const std::string	_NAME;

    caca_canvas_t		*_cv;
    caca_display_t		*_dp;
    caca_event_t		_ev;

    void 		initColorTab();
    void 		initInputTab();
    void 		blitBackground(const Sptr_t<map_t> map);
  public:
			LibCaca();
			~LibCaca();

    virtual std::string const	&getName() const override;
    virtual InputType	getInput() const override;
    virtual void 	createWindow() override;
    virtual void 	quitWindow() override;
    virtual void	blitText(std::string const &text,
						retromania::pos_t const &pos,
						int const fontSize,
						ColorType const color) override;
    virtual void 	blitTile(const int, retromania::pos_t &) override ;
    virtual void	display(const Sptr_t<map_t> map = nullptr) override;
};
}
#endif			/* !LIBACACA_H */
