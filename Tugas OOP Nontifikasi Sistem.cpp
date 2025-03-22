#include <iostream>
#include <memory>
#include <unordered_map>

class Notification {
public:
    virtual void send(const std::string& recipient, const std::string& message) = 0;
    virtual ~Notification() {}
};

class EmailNotification : public Notification {
public:
    void send(const std::string& recipient, const std::string& message) override {
        std::cout << "[EMAIL] Mengirim Email ke " << recipient << " dengan pesan: " << message << std::endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(const std::string& recipient, const std::string& message) override {
        std::cout << "[SMS] Mengirim SMS ke " << recipient << " dengan pesan: " << message << std::endl;
    }
};

class PushNotification : public Notification {
public:
    void send(const std::string& recipient, const std::string& message) override {
        std::cout << "[PUSH] Mengirim Push Notification ke " << recipient << " dengan pesan: " << message << std::endl;
    }
};

void send_notification(const std::string& notification_type, const std::string& recipient, const std::string& message) {
    static std::unordered_map<std::string, std::shared_ptr<Notification>> notification_map = {
        {"email", std::make_shared<EmailNotification>()},
        {"sms", std::make_shared<SMSNotification>()},
        {"push", std::make_shared<PushNotification>()}
    };

    auto it = notification_map.find(notification_type);
    if (it != notification_map.end()) {
        std::cout << "\n--- Mengirim Notifikasi ---\n";
        it->second->send(recipient, message);
        std::cout << "--- Notifikasi Terkirim ---\n";
    }
    else {
        std::cout << "Jenis notifikasi tidak didukung" << std::endl;
    }
}

int main() {
    std::cout << "=== Sistem Notifikasi ===\n";
    send_notification("email", "temanku", "Selamat datang di layanan kami!");
    send_notification("sms", "085990914552", "Promo terbaru untuk Anda!");
    send_notification("push", "saudara", "Ada update baru di aplikasi!");
    return 0;
}