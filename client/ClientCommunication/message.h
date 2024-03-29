#ifndef MESSAGE_H
#define MESSAGE_H

/*
* message.h
* ----------------------
* COMP3004A: cuTPS Project
* Team Name: teaQup
* Author(s):
* Bernard Llanos ID: 100793648
* Brandon Keyes  ID: 100897196
* Analee Chicot  ID: 100822791
* Remy Gratwohl  ID: 100891970
*
* Message class:
* - Abstract class defining messages to be sent over the network.
*
* Traceability: CT-007
*
* Acknowledgements: None
*/

#include <QObject>
#include <QDataStream>
#include "../server/ServerCommunication/serializableqobject.h"
#include "../server/ServerCommunication/messageroutingtypes.h"
#include "../server/UserManagement/user.h"

class Message : public SerializableQObject
{
   Q_OBJECT
   Q_PROPERTY(quint16 destType READ getDestType_quint16 WRITE setDestType_quint16)
   Q_PROPERTY(quint16 actionType READ getActionType_quint16 WRITE setActionType_quint16)
   Q_PROPERTY(bool userExists READ getUserExists WRITE setUserExists)

protected:
    /* Constructor
     *   To be used to create a container for deserialized data.
     * Side Effects: None
     */
    Message(void);

    /* Constructor
     * in: Destination subsystem
     * in: Verb of the message
     * in: User associated with the message
     *      Can be null for messages that are to be sent to the
     *      client processes.
     *      Treated as a shared pointer.
     * Side Effects: None
     */
    Message(DEST_TYPE, ACTION_TYPE, User*);

public:
    virtual ~Message(void);

public:
    DEST_TYPE getDestType()   const { return destType;   }
    ACTION_TYPE getActionType() const { return actionType; }

    quint16 getDestType_quint16()   const { return (quint16)destType;   }
    quint16 getActionType_quint16() const { return (quint16)actionType; }

    void setDestType_quint16(quint16 dt)   { destType = static_cast<DEST_TYPE>(dt); }
    void setActionType_quint16(quint16 at) { actionType = static_cast<ACTION_TYPE>(at); }

    bool getUserExists() const { return userExists; }
    void setUserExists(bool value) { userExists = value; }

    /* Member Function: getUser
     *   Returns the User pointer stored in this object.
     *   This is a shared pointer if the object was created
     *     by passing in a User at construction,
     *     but is owned by this object if the pointer was
     *     instead initialized by deserialization.
     *
     *  See also extractUser()
     */
    User* getUser(void) const { return user; }

    /* Member Function: extractUser
     *   Returns the User pointer stored in this object,
     *     and transfers ownership to the caller.
     *   This object's User pointer is nullified.
     */
    User* extractUser(void);

protected:
    /* Member Function: insertToDataStream
     *   Serialization function, which inserts the appropriate type constant
     *     into the data stream before the object's contents
     * inout: Data output stream
     * in: Type constant to use for deserialization.
     * Side Effects: None
     * Return Value: None
     */
    virtual void insertToDataStream(QDataStream& ds, SerializableType type) const;

public:
    /* Member Function: insertToDataStream
     *   Serialization function, which inserts the appropriate type constant
     *     into the data stream before the object's contents
     * inout: Data output stream
     * Side Effects: None
     * Return Value: None
     */
    virtual void insertToDataStream(QDataStream& ds) const = 0;

    /* Member Function: extractFromDataStream
     *   Deserialization function
     * inout: Data input stream
     * Side Effects: None
     * Return Value: None
     */
    virtual void extractFromDataStream(QDataStream& ds);

private:
    DEST_TYPE destType;
    ACTION_TYPE actionType;
    User* user;
    bool userIsShared; // Flag indicating ownership of 'user'
    bool userExists; // server sends null users, need to check for this
};

#endif // MESSAGE_H
