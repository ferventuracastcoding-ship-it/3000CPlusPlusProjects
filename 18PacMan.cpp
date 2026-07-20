#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

const int TILE = 32;


vector<string> maze =
{
"########################",
"#..........##..........#",
"#.####.....##.....####.#",
"#......................#",
"#.####.#.######.#.####.#",
"#......#....##....#....#",
"######.####.##.####.####",
"#............P.........#",
"####.##.########.##.###",
"#....##....##....##....#",
"#.########.##.########.#",
"#......................#",
"#.####.....##.....####.#",
"#..........##..........#",
"########################"
};



struct Entity
{
    sf::RectangleShape shape;
    float speed;
};



class Pacman: public Entity
{

public:

    Pacman()
    {
        shape.setSize(
            sf::Vector2f(TILE-4,TILE-4)
        );

        shape.setFillColor(
            sf::Color::Yellow
        );

        speed=160;
    }


    void move(float dx,float dy)
    {
        shape.move(dx,dy);
    }
};



class Ghost: public Entity
{

public:

    Ghost(float x,float y,sf::Color color)
    {
        shape.setSize(
            sf::Vector2f(TILE-4,TILE-4)
        );

        shape.setPosition(x,y);

        shape.setFillColor(color);

        speed=70;
    }


    void update(float dt)
    {

        shape.move(speed*dt,0);


        if(shape.getPosition().x > 700)
            speed=-70;


        if(shape.getPosition().x < 50)
            speed=70;
    }

};




bool collision(
sf::RectangleShape &player,
vector<sf::RectangleShape>&walls)
{

    for(auto &wall:walls)
    {
        if(player.getGlobalBounds()
        .intersects(wall.getGlobalBounds()))
            return true;
    }

    return false;
}



int main()
{

sf::RenderWindow window(
sf::VideoMode(768,480),
"Advanced Pac-Man"
);



Pacman player;


vector<sf::RectangleShape> walls;
vector<sf::CircleShape> pellets;



for(int y=0;y<maze.size();y++)
{
    for(int x=0;x<maze[y].size();x++)
    {

        if(maze[y][x]=='#')
        {
            sf::RectangleShape wall;

            wall.setSize(
            sf::Vector2f(TILE,TILE));


            wall.setPosition(
            x*TILE,
            y*TILE);


            wall.setFillColor(
            sf::Color::Blue);


            walls.push_back(wall);
        }


        if(maze[y][x]=='.')
        {
            sf::CircleShape pellet(5);

            pellet.setFillColor(
            sf::Color::White);


            pellet.setPosition(
            x*TILE+12,
            y*TILE+12);


            pellets.push_back(pellet);
        }


        if(maze[y][x]=='P')
        {
            player.shape.setPosition(
            x*TILE,
            y*TILE);
        }

    }
}



vector<Ghost> ghosts;

ghosts.push_back(
Ghost(200,200,sf::Color::Red)
);

ghosts.push_back(
Ghost(400,200,sf::Color::Green)
);

ghosts.push_back(
Ghost(600,300,sf::Color::Magenta)
);



int score=0;
int lives=3;


sf::Clock clock;



while(window.isOpen())
{

sf::Event event;


while(window.pollEvent(event))
{
    if(event.type==
    sf::Event::Closed)
        window.close();
}



float dt=
clock.restart().asSeconds();



float dx=0;
float dy=0;



if(sf::Keyboard::isKeyPressed(
sf::Keyboard::Left))
dx=-player.speed*dt;


if(sf::Keyboard::isKeyPressed(
sf::Keyboard::Right))
dx=player.speed*dt;


if(sf::Keyboard::isKeyPressed(
sf::Keyboard::Up))
dy=-player.speed*dt;


if(sf::Keyboard::isKeyPressed(
sf::Keyboard::Down))
dy=player.speed*dt;



player.move(dx,dy);



if(collision(player.shape,walls))
{
    player.move(-dx,-dy);
}



// Eat pellets

for(auto it=pellets.begin();
it!=pellets.end();)
{

if(player.shape
.getGlobalBounds()
.intersects(
it->getGlobalBounds()))
{

it=pellets.erase(it);

score+=10;

}
else
it++;

}



// Ghost AI

for(auto &ghost:ghosts)
{

ghost.update(dt);


if(player.shape
.getGlobalBounds()
.intersects(
ghost.shape.getGlobalBounds()))
{

lives--;

player.shape.setPosition(100,100);

}

}




window.clear(
sf::Color::Black);



for(auto &wall:walls)
window.draw(wall);


for(auto &p:pellets)
window.draw(p);



window.draw(player.shape);



for(auto &g:ghosts)
window.draw(g.shape);



window.display();



}


cout<<"Final Score: "
<<score<<endl;

cout<<"Lives: "
<<lives;


return 0;
}
