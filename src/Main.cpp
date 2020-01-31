#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main(int const ac, char const *const *av, char const *const *env)
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "GGJ2020");
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();
		// Update the window
		window.display();
	}
    return 0;
}
