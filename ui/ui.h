
#ifndef UI_H
#define UI_H



class UI {
    UserController& user_controller;
    //show()
    public:
    UI(UserController& ctrl) : userController(ctrl) {}
    void reserve_equipment_ui();
};



#endif //UI_H
