#include <iostream>
using namespace std;

class Book
{
public:
    int ReservationId;
    int PatronId;
    int BookId;
    float ReservationTime;
    string status;

    Book *nextBook;

    Book(int a, int b, int c, float d) : ReservationId(a), PatronId(b), BookId(c), ReservationTime(d), status("Pending") {};
};

class Management
{
public:
    Book *front;
    Book *rear;

    Management() : front(nullptr), rear(nullptr) {};

    void ReserveBook(int reservation_id, int patron_id, int book_id, float reservation_time)
    {

        Book *newBook = new Book(reservation_id, patron_id, book_id, reservation_time);

        if (front == nullptr and rear == nullptr)
        {
            front = newBook;
            rear = newBook;
        }

        else
        {
            rear->nextBook = newBook;
            rear = newBook;
        }
    }

    void ProcessReservation()
    {

        if (front == nullptr and rear == nullptr)
        {
            cout << "No Books to Process !!" << endl;
            return;
        }

        else
        {
            front->status = "Completed";
            front = front->nextBook;
        }
    }

    void dis()
    {
        Book *temp = front;

        while (temp)
        {
            if (temp->ReservationId){
                cout << "ID : " << temp->ReservationId << endl;
            }
            temp = temp->nextBook;
        }
    }
    void Display()
    {
        Book *temp = front;
        int count = 1;

        while (temp)
        {

            if (temp->status == "Pending")
            {
                cout << "Book : " << count << endl;
                cout << "Reservation Id : " << temp->ReservationId << endl;
                cout << "Patron Id : " << temp->PatronId << endl;
                cout << "ReservationTime : " << temp->ReservationTime << endl;
                cout << "Status : " << temp->status << endl;

                count++;
            }
        }
    }
};

int main()
{

    Management Books;
    Books.ReserveBook(1, 2, 3, 4.90);
    Books.ReserveBook(2, 3, 4, 5.90);
    Books.ReserveBook(3, 4, 5, 6.90);
    Books.ReserveBook(4, 5, 6, 7.90);

    Books.ProcessReservation();

    Books.dis();

    return 0;
}
