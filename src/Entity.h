#ifndef ENTITY_H
#define ENTITY_H


/**
 *  @brief Represents a game entity with position, velocity, and health.
 * 
 *  
 */


class Entity
{
    public:

    //default constructor - creates an entity with default values   
    Entity();

    //parameterized constructor - init pos, velocity, and hp
    Entity(float x, float y, float vx, float vy, int health);

    //initializes the entity with given position, velocity, and health
    void init(float x, float y, float vx, float vy, int health);
    
    bool Entity::isDead() const; //checks if the entity is dead
    float Entity::getX() const; //gets X pos of entity
    float Entity::getY() const; //gets Y pos of entity
    int Entity::getHealth() const; //gets health of entity

    private:
        float x_;
        float y_;
        float vx_;
        float vy_;
        int health_;
};



#endif // ENTITY_H