#ifndef SERIALIZABLETYPES_H
#define SERIALIZABLETYPES_H
/*
* serializabletypes.h
* ----------------------
* COMP3004A: cuTPS Project
* Team Name: teaQup
* Author(s):
* Bernard Llanos ID: 100793648
* Brandon Keyes ID:  100897196
* Analee Chicot ID:  100822791
* Remy Gratwohl ID:  100891970
*
* A list of the types of custom QObjects classes
* that can undergo serialization.
*
* Traceability: P2SUB-001-001
* References: N/A
*
* Acknowledgements: None
*/

enum SerializableType {
    BOOK,
    CHAPTER,
    CHAPTERSECTION,
    PURCHASEDETAILS, // Not used externally to the PurchasingDetails class
    ORDEROBJ,
    BILLINGINFO, // Not used externally to the BillingInformation class
    USEROBJ,
    TERMOBJ,
    COURSEOBJ,
    ERRORMESSAGE,
    DATAMESSAGE
};

#endif // SERIALIZABLETYPES_H
