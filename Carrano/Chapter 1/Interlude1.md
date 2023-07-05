/*Question 1 Revise the parameterized constructor to call the
base-class’s constructor instead of MagicBox’s constructor */

 @file MagicBox.cpp
template <class ItemType>
MagicBox<ItemType>::MagicBox()
{
    PlainBox<ItemType>();
    (continues)44 C++ INTERLUDE 1 C++ Classes
        firstItemStored = false; // Box has no magic initially
} // end default constructor
template <class ItemType>
MagicBox<ItemType>::MagicBox(const ItemType &theItem) //THIS IS THE PARAMETERIZED CONSTRUCTOR
{
    firstItemStored = false; // Box has no magic initially
    setItem(theItem);
    // Box has magic now
} // end constructor
template <class ItemType>
void MagicBox<ItemType>::setItem(const ItemType &theItem)
{
    if (!firstItemStored)
    {
        PlainBox<ItemType>::setItem(theItem);
        firstItemStored = true; // Box now has magic
    }                           // end if
} // end setItem */

/* Answer: */

template <class ItemType>
MagicBox<ItemType>::MagicBox(const ItemType &theItem)
{
    Plainbox<ItemType>::setItem(theItem);
    firstItemStored = true;
}