#include "MenuWindow.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "example.gnome.org");

  MenuWindow menu_window;

  // Показывает окно и возвращает управление в момент его закрытия.
  return app->run(menu_window);
}