#include "datamessage.h"

DataMessage::DataMessage(void) :
    Message(), data(0)
{}

DataMessage::DataMessage(DEST_TYPE dt, ACTION_TYPE at, User* u, QVector<SerializableQObject *> data_) :
    Message(dt, at, u), data(data_)
{}

DataMessage::~DataMessage(void) {
    QVectorIterator<SerializableQObject*> i(*data);
    while (i.hasNext()) {
        delete (i.next());
    }
    delete data;
    data = 0;
}

void DataMessage::insertToDataStream(QDataStream& ds) const {
    Message::insertToDataStream(ds, DATAMESSAGE);
}

void DataMessage::extractFromDataStream(QDataStream& ds) {

}
