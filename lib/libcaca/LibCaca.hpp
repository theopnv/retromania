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
    using colorTab_t	= std::map<ColorType, uint8_t>;
    using inputTab_t	= std::map<int, InputType>;

    static const std::string	_NAME;

    colorTab_t		_colorTab;
    inputTab_t		_inputTab;
    caca_canvas_t	*_cv;
    caca_display_t	*_dp;
    caca_event_t	_ev;

    void 		initColorTab();
    void 		initInputTab();
    void 		blitBackground(const Sptr_t<Map> map);
  public:
			LibCaca();
			~LibCaca();

    virtual const std::string& getName() const override;
    virtual InputType	getInput() const override;
    virtual void 	createWindow() override;
    virtual void 	quitWindow() override;
    virtual void	blitText(std::string const &text,
						retromania::Pos const &pos,
						int const fontSize,
						ColorType const color) override;
    virtual void 	blitTile(const int, retromania::Pos &) override ;
    virtual void	display(const Sptr_t<Map> map = nullptr) override;
};
}
#endif			/* !LIBACACA_H */
