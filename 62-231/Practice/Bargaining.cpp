#include <simplecpp>

class Bargaining {
private:
    double minPrice;
    int maxAttempts;
    double sellerPrice;
    double buyerPrice;

public:
    Bargaining(double min, int max) : minPrice(min), maxAttempts(max) {
        sellerPrice = minPrice;
    }

    void negotiate() {
        int attempts = 0;
        bool dealClosed = false;

        while (attempts < maxAttempts && !dealClosed) {
            cout << "Buyer, please enter your offer: ";
            cin >> buyerPrice;

            if (buyerPrice >= minPrice) {
                cout << "Seller accepts the offer of $" << buyerPrice << endl;
                dealClosed = true;
            } else {
                double counterOffer = (minPrice + buyerPrice) / 2.0;
                cout << "Seller counteroffers: $" << counterOffer << endl;
                attempts++;
            }
        }

        if (!dealClosed) {
            cout << "Bargaining failed. Buyer walked away." << endl;
        }
    }
};

int main() {
    initCanvas("Bargaining", 400, 200);

    double minPrice;
    int maxAttempts;

    cout << "Enter the minimum price: ";
    cin >> minPrice;

    cout << "Enter the maximum number of negotiation attempts: ";
    cin >> maxAttempts;

    Bargaining bargaining(minPrice, maxAttempts);
    bargaining.negotiate();

    closeCanvas();
    return 0;
}
