//
// Created by Codie Cottrell on 3/2/21.
//

#ifndef FERNQUEST_INTERACT_H
#define FERNQUEST_INTERACT_H


class Interact {
private:
    bool interacted;
public:
    //Interact();
    static std::string playerMove();
    static std::string playerItemInteract(std::string item);
};


#endif //FERNQUEST_INTERACT_H
