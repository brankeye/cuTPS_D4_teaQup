#include "shoppingcarttable.h"
#include "../server/ContentManagement/contentitem.h"
#include "../server/ContentManagement/book.h"
#include "../server/ContentManagement/chapter.h"
#include "../server/ContentManagement/chaptersection.h"

ShoppingCartTable::ShoppingCartTable(QObject *parent, QTableWidget *table) :
    ItemTable(parent, table)
{
    shoppingItems = new QVector<SerializableQObject*>();
}

ShoppingCartTable::~ShoppingCartTable() {}

bool ShoppingCartTable::updateTableView(QVector<SerializableQObject *>* contentList)
{
    int listSize = contentList->size();
    for(int i = 0; i < listSize; ++i) {
        shoppingItems->push_back(contentList->at(i));
        ContentItem* content = qobject_cast<ContentItem*>(contentList->at(i));

        QTableWidgetItem* itemTitle;
        QTableWidgetItem* itemType;
        QTableWidgetItem* itemCourseID;

        // set title and course id values
        itemTitle = new QTableWidgetItem(content->getTitle());
        itemCourseID = new QTableWidgetItem((quint64)content->getCourseID());

        // determine the type of the content item
        Book* book = 0;
        Chapter* chapter = 0;
        ChapterSection* chapterSection = 0;
        if((book = qobject_cast<Book*>(content)) != 0) {
            itemType = new QTableWidgetItem("Book");
        } else if((chapter = qobject_cast<Chapter*>(content)) != 0) {
            itemType = new QTableWidgetItem("Chapter");
        } else if((chapterSection = qobject_cast<ChapterSection*>(content)) != 0) {
            itemType = new QTableWidgetItem("ChapterSection");
        }

        // make the cells uneditable
        itemTitle->setFlags(itemTitle->flags() ^ Qt::ItemIsEditable);
        itemType->setFlags(itemType->flags() ^ Qt::ItemIsEditable);
        itemCourseID->setFlags(itemCourseID->flags() ^ Qt::ItemIsEditable);

        // add the text items to the table
        contentTable->setRowCount(listSize);
        contentTable->setItem(i, 0, itemTitle);
        contentTable->setItem(i, 1, itemType);
        contentTable->setItem(i, 2, itemCourseID);

        // adjust column width to fit all contents
        contentTable->resizeColumnsToContents();
    }
    return true;
}

void ShoppingCartTable::itemTitleClicked(int row, int col)
{

}
