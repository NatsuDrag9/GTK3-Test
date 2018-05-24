#include <gtk/gtk.h>
#include <iostream>

using namespace std;

static void MakeMainWindowControls (GtkApplication* app,  gpointer user_data)
{
  //  Declaring the required pointers for creating a window with menus  
  GtkWidget *window;
  GtkWidget *menu_box;                                              // Box for alignment
  GtkWidget *packed_menu_box;                                       // Stores the packed box
  GtkWidget *FileMenu;                                              // File Menu
  GtkWidget *EditMenu;                                              // Edit Menu
  GtkWidget *settings;                                              // Settings Menu
  GtkWidget *InstructionMenu;                                       // Instruction Menu
  GtkWidget *compile;                                               // Compile Menu
  GtkWidget *help;                                                  // Help Menu
  GtkWidget *SimulateMenu;                                          // Simulate Menu
  GtkWidget *menu_bar;                                              // Menu Bar
  GtkWidget *file_label;                                            // File menu label
  GtkWidget *edit_label;                                            // Edit menu label
  GtkWidget *instruction_label;                                     // Instruction menu label
  GtkWidget *settings_label;                                        // Settings menu label
  GtkWidget *compile_label;                                         // Compile menu label
  GtkWidget *help_label;                                            // Help menu label
  GtkWidget *simulate_label;                                        // Simulate menu label
  GtkWidget *file_menu_items;                                       // File menu item
  GtkWidget *edit_menu_items;                                       // Edit menu item
  GtkWidget *file_menu_separator;                                   // File menu separator
  GtkWidget *edit_menu_separator;                                   // Edit menu separator

  char file_contents[6][20] = {"New", "Open", "Save", "Save As", "Export As Text", "Exit"};
  char edit_contents[8][60] = {"Undo", "Redo", "Insert Rung Before", "Insert Rung After", "Move Selected Rung Up", "Move Selected Rung Down", "Delete Selected Element", "Delete Rung"};
  char file_buffer[128];
  char edit_buffer[128];

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "LDMicro");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 200);

  // Creating a box for desired orientation
  menu_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

  // Create new menu bar to hold menu and add it to window
  menu_bar = gtk_menu_bar_new();

  // Creating various menus
  FileMenu = gtk_menu_new();
  file_label = gtk_menu_item_new_with_label("File");
  EditMenu = gtk_menu_new();
  edit_label = gtk_menu_item_new_with_label("Edit");
  settings = gtk_menu_new();
  settings_label = gtk_menu_item_new_with_label("Settings");
  InstructionMenu = gtk_menu_new();
  instruction_label = gtk_menu_item_new_with_label("Instructions");
  SimulateMenu = gtk_menu_new();
  simulate_label = gtk_menu_item_new_with_label("Simulate");
  compile = gtk_menu_new();
  compile_label = gtk_menu_item_new_with_label("Compile");
  help = gtk_menu_new();
  help_label = gtk_menu_item_new_with_label("Help");

  for (int i = 0; i < 6; i++){
    sprintf(file_buffer, file_contents[i]);                                  // Copy names to the buffer
    file_menu_items = gtk_menu_item_new_with_label(file_buffer);             // Create a new menu item with a name
    gtk_menu_shell_append(GTK_MENU_SHELL (FileMenu), file_menu_items);       // Appending menu items
    if (i == 3 || i == 4 ){
      file_menu_separator = gtk_separator_menu_item_new();
      gtk_menu_shell_append(GTK_MENU_SHELL(FileMenu), file_menu_separator);
    }
  }

  for (int i = 0; i < 8; i++){
    sprintf(edit_buffer, edit_contents[i]);                                   // Copy names to the buffer
    edit_menu_items = gtk_menu_item_new_with_label(edit_buffer);              // Create a new menu item with a name
    gtk_menu_shell_append(GTK_MENU_SHELL (EditMenu), edit_menu_items);        // Appending menu items
    if (i == 1 || i == 5){
      edit_menu_separator = gtk_separator_menu_item_new();
      gtk_menu_shell_append(GTK_MENU_SHELL(EditMenu), edit_menu_separator);
    }
  }

  // Creating submenus for each menu   
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_label), FileMenu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit_label), EditMenu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(settings_label), settings);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(instruction_label), InstructionMenu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(simulate_label), SimulateMenu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(compile_label), compile);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(help_label), help);

  // Appending the menu item to the menu bar
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_label);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), edit_label);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), settings_label);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), instruction_label);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), simulate_label);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), compile_label);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), help_label);

  // Packing the menu bar into the box for alignment
  gtk_box_pack_start(GTK_BOX(menu_box), menu_bar, FALSE, FALSE, 0);

  // Adding the packed box to the window
  gtk_container_add(GTK_CONTAINER(window), menu_box);

  // Displaying the window
  gtk_widget_show_all(window);
  
}

int main (int argc, char **argv)
{
  GtkApplication *app;
  int status;
  app = gtk_application_new ("IITB.project.LDMicro", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (MakeMainWindowControls), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);
  return status;
}