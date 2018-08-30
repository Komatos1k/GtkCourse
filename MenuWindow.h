#ifndef MENU_WINDOW
#define MENU_WINDOW

#include <gtkmm.h>

class MenuWindow : public Gtk::Window
{
    public:
        MenuWindow();
        virtual ~MenuWindow();

    private:
        //Signals
        void on_button_clicked(const Glib::ustring& data);
        void on_button_quit();

        //Children Widget
        Gtk::Grid menu_grid;
        Gtk::Button but_add_menu, but_del_menu, but_ls_menu, but_quit_menu;
};

#endif /* MENU_WINDOW */