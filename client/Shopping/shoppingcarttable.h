#ifndef SHOPPINGCARTTABLE_H
#define SHOPPINGCARTTABLE_H

#include "../ClientInterface/itemtable.h"

class ShoppingCartTable : public ItemTable
{
    Q_OBJECT
public:
    ShoppingCartTable(QObject *parent, QTableWidget *table);
    ~ShoppingCartTable();

    /* Member Function: updateTableView
     *   Displayes the names of content items in a list
     * in: A list of content items to view
     * Side Effects: None
     * Return Value: Success indicator
     */
    virtual bool updateTableView(QVector<SerializableQObject *>* contentList);

public slots:
    virtual void itemTitleClicked(int row, int col);

private:
    QVector<SerializableQObject *>* shoppingItems;

};

#endif // SHOPPINGCARTTABLE_H