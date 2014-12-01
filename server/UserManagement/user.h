#ifndef USER_H
#define USER_H

/*
* user.h
* ----------------------
* COMP3004A: cuTPS Project
* Team Name: teaQup
* Author(s):
* Bernard Llanos ID: 100793648
* Brandon Keyes  ID: 100897196
* Analee Chicot  ID: 100822791
* Remy Gratwohl  ID: 100891970
*
* User class:
* - represents either Student, ContentManager, or Administrator
* - is the user of the cuTPS system
*
* Traceability: ET-016
*
* Acknowledgements: None
*/

#include "../ServerCommunication/serializableqobject.h"
#include <QString>

class User : public SerializableQObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(quint16 type READ getType WRITE setType)
    Q_PROPERTY(quint16 id READ getID WRITE setID)
public:

    enum TYPE { ADMIN, STUDENT, CONTENTMGR };

    /* Constructor
     *   To be used by the client process
     *   to create a User object that gets fully initialized
     *   on the server and then sent back to complete
     *   the authentication process.
     * in: Username
     * Side Effects: None
     */
    User(const QString& name);

    /* Constructor
     *   Creates a fully-initialized User object
     * in: Username
     * in: Type of user
     * in: User ID
     * Side Effects: None
     */
    User(const QString& name, const TYPE type, const quint16 id);

    /* Member Function: insertToDataStream
     *   Serialization function, which must be overridden to
     *     insert the appropriate type constant
     *     into the data stream before the object's contents
     * inout: Data output stream
     * Side Effects: None
     * Return Value: None
     */
    virtual void insertToDataStream(QDataStream& ds) const;

    QString getName() const { return name; }
    void setName(const QString& n) { name = n; }

    quint16 getType()   const { return (quint16)type;   }
    void setType(quint16 t)   { type = static_cast<TYPE>(t); }

    quint16 getID()   const { return (quint16)identifier;   }
    void setID(quint16 id)   { identifier = static_cast<TYPE>(id); }

signals:

public slots:

private:
    QString name;
    TYPE type;
    quint16 identifier;
};

#endif // USER_H