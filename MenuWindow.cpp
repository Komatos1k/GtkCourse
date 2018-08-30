#include <iostream>
#include "MenuWindow.h"

MenuWindow::MenuWindow()
:   but_add_menu("Add Task"),
    but_ls_menu("List Task"),
    but_del_menu("Delete Task"),
    but_quit_menu("Exit")
{
    set_title("Menu::TodoList");
    set_border_width(20);

    add(menu_grid);

    menu_grid.add(but_add_menu);
    menu_grid.add(but_del_menu);
    menu_grid.attach_next_to(but_ls_menu, but_add_menu, Gtk::POS_BOTTOM, 2, 1);
    //menu_grid.attach_next_to(but_del_menu, but_ls_menu, Gtk::POS_BOTTOM, 1, 1);
    menu_grid.attach_next_to(but_quit_menu, but_ls_menu, Gtk::POS_BOTTOM, 2, 1);

    but_add_menu.signal_clicked().connect(
        sigc::bind<Glib::ustring>( sigc::mem_fun(*this,
        &MenuWindow::on_button_clicked), "Add") );
    but_ls_menu.signal_clicked().connect(
        sigc::bind<Glib::ustring>( sigc::mem_fun(*this,
        &MenuWindow::on_button_clicked), "List") );
    but_del_menu.signal_clicked().connect(
        sigc::bind<Glib::ustring>( sigc::mem_fun(*this,
        &MenuWindow::on_button_clicked), "Delete") );
    but_quit_menu.signal_clicked().connect(
        sigc::mem_fun(*this, 
        &MenuWindow::on_button_quit) );

    show_all_children();
}

MenuWindow::~MenuWindow()
{
}

void MenuWindow::on_button_quit()
{
    std::cout << "Exit." << std::endl;
    hide();
}

void MenuWindow::on_button_clicked(const Glib::ustring& data)
{
    std::cout << data << " in the menu window." << std::endl;
}