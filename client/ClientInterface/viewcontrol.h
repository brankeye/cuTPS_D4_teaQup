#ifndef VIEWCONTROL_H
#define VIEWCONTROL_H

/*
* viewcontrol.h
* ----------------------
* COMP3004A: cuTPS Project
* Team Name: teaQup
* Author(s):
* Bernard Llanos ID: 100793648
* Brandon Keyes  ID: 100897196
* Analee Chicot  ID: 100822791
* Remy Gratwohl  ID: 100891970
*
* ViewControl class:
* - Top-level control class for the client interface subsystem
* - Responsible for managing the client user interface and other control objects
*
* Traceability: CT-014
*
* Acknowledgements: None
*/

#include <QObject>
#include <QWidget>

#include "loginwindow.h"
#include "mainwindow.h"

#include "ClientCommunication/clientdispatcher.h"

#include "ContentView/contentviewcontrol.h"
#include "CourseView/courseviewcontrol.h"
#include "Shopping/shoppingcartcontrol.h"

class UserAuthenticationControl;

class ViewControl : public QObject
{
    Q_OBJECT
public:
     enum TYPE {CONTENT_VIEW = 0, COURSE_VIEW, SHOPPING_VIEW, BILLING_VIEW};

     // temp func to send messages to server
     bool begin();

     /* Member Function: processMsg
      *   Let the subsystem handle the message
      * in: The message object to handle
      * Side Effects: msg is deleted
      * Return Value: Success indicator
      */
     bool processMsg(Message *msg);

     bool changeView(TYPE subsystem);
     bool requestAuthentication(OBJ_ID_TYPE id);

     void displayCommunicationError();
     void displayErrorString(QString &err);

     User* getCurrentUser(void) const { return currentUser; }
     bool setCurrentUser(User* user);

private:
    User                      *currentUser;  // The User currently logged in

    LoginWindow               *loginWindow;
    MainWindow                *mainWindow;

    UserAuthenticationControl *authenticator;

    /* Subsystem Controllers */
    ClientDispatcher          *clientDispatcher;
    ContentViewControl        *contentController;
    CourseViewControl         *courseController;
    ShoppingCartControl       *shoppingController;

    bool displayView(QWidget *widget);
    bool changeWindow(QWidget *window);

};

#endif // VIEWCONTROL_H
