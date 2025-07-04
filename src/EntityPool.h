#ifndef ENTITY_POOL_H
#define ENTITY_POOL_H

#include <cstddef>
#include <vector>
#include <new>
#include <cassert>

/**
 *  @brief memory pool for managing entities.
 * 
 *  
 *  
 */

 template <typename T, std::size_t N>
 class EntityPool{
    public:
        EntityPool();
        ~EntityPool();

        //acquire objects - returns a pointer or nullptr if pool is full
        T* acquire();

        void release(T* object); //Release an object - calls destructor and recycles storage

        //get pointers to all active entities
        std::vector<T*> activeEntities() const;

        std::size_t size() const { return activeCount_}
        std::size_t capacity() const { return N;}
        

    private:
        //track active obj count
        std::size_t activeCount_; 

        //raw storage buffer for N objects - align as T instead of unsigned char
        alignas(T) unsigned char buffer_[N* sizeof(T)];

        std::vector<std::size_t> freeIndices_; //indices of free slots in the buffer


        
 };

#include "EntityPool.inl"
#endif // ENTITY_POOL_H