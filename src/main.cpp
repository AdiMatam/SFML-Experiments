#include "pch.hpp"
#include "helpers.hpp"
#include "checkers.hpp"

/* EXPERIMENTATION - IGNORE FOR PRES.
void config(tgui::Button::Ptr button) {
	button->setSize(tgui::Layout2d(30, 30));
	button->setOrigin(sf::Vector2f(0.f, 0.f));
	button->setPosition(tgui::Layout2d("parent.w/2 - w - 5", "parent.h - h - 5"));
}

 	tgui::Gui gui(window);
	tgui::Button::Ptr right = tgui::Button::create();
	config(right);
	gui.add(right);
*/

int main() {
	const std::string TITLE = "Chinese Checkers";
	sf::ContextSettings set;
	set.antialiasingLevel = 8;

	sf::RenderWindow window(
		sf::VideoMode(SIZE, SIZE), TITLE, sf::Style::Default, set
	);
	sf::Event ev;
	ChineseCheckers game(&window, 2);
	
	while (window.isOpen()) {
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed or keyPressed(ev, sf::Keyboard::Escape))
				window.close();

			else if (keyPressed(ev, sf::Keyboard::Left) or keyPressed(ev, sf::Keyboard::Right))
				game.spin(ev.key.code);

			else if (!game.isOver()) {
				if (mousePressed(ev, sf::Mouse::Left))
					game.processClick(ev.mouseButton.x, ev.mouseButton.y);
				
				else if (keyPressed(ev, sf::Keyboard::Enter) and game.movedAtAll())
					game.nextTurn();

				else if (keyPressed(ev, sf::Keyboard::Z) and ev.key.control)
					game.undo();
			}
		}
		game.draw();
	}
	return 0;
}
