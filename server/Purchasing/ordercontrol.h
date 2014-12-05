#ifndef ORDERCONTROL_H
#define ORDERCONTROL_H

/*
* ordercontrol.h
* ----------------------
* COMP3004A: cuTPS Project
* Team Name: teaQup
* Author(s):
* Bernard Llanos ID: 100793648
* Brandon Keyes  ID: 100897196
* Analee Chicot  ID: 100822791
* Remy Gratwohl  ID: 100891970
*
* OrderControl class:
* - handles the Student user's orders.
*
* Traceability: CT-015
*
* Acknowledgements: None
*/

#include "../util/abstractmanager.h"

class OrderControl : public AbstractManager
{
    Q_OBJECT
public:
    /* Constructor
     * in: Dispatcher to use for sending messages to the client
     *       (Also the parent of this object.)
     * Side Effects: None
     * All input pointers are treated as shared pointers.
     */
    OrderControl(ServerDispatcher *dispatcher);

    /* Member Function: processMsg
     *   Handles a message received from the dispatcher,
     *     possibly resulting in messages sent back through the dispatcher
     * in: Message to be processed
     * Side Effects: None
     * Return Value: True, if the operation succeeded.
     */
    virtual bool processMsg(const Message* msg);
};

#endif // ORDERCONTROL_H
