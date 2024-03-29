#ifndef USERAUTHENTICATIONCONTROL_H
#define USERAUTHENTICATIONCONTROL_H

/*
* userauthenticationcontrol.h
* ----------------------
* COMP3004A: cuTPS Project
* Team Name: teaQup
* Author(s):
* Bernard Llanos ID: 100793648
* Brandon Keyes  ID: 100897196
* Analee Chicot  ID: 100822791
* Remy Gratwohl  ID: 100891970
*
* UserAuthenticationControl class:
* - Manages the user authentication request for the client
*
* Traceability: CT-030
*
* Acknowledgements: None
*/

#include <QObject>
#include "../util/abstractviewcontroller.h"

class UserAuthenticationControl : public AbstractViewController
{
    Q_OBJECT
public:
    /* Constructor
     *   Proxy of the AbstractViewController constructor.
     */
    UserAuthenticationControl(ViewControl *viewControl, ClientDispatcher *dispatcher);

    /* Member Function: requestAuthentication
     *   Queries for the current user's full information from the server,
     *     given the user ID number.
     * in: User ID number
     * Side Effects: None
     * Return Value: Returns the result of ClientDispatcher::deliverMsg()
     */
    bool requestAuthentication(OBJ_ID_TYPE id);

    /* Member Function: processMsg
     *   Handles a message received from the dispatcher.
     * in: Message to be processed
     * Side Effects: None
     * Return Value: True, if the operation succeeded.
     */
    virtual bool processMsg(Message* msg);

signals:

public slots:

private:
    // Has authentication been completed?
    bool isAuthenticated;
};

#endif // USERAUTHENTICATIONCONTROL_H
