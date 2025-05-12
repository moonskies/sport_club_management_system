//
// Created by andre on 12/05/2025.
//
#pragma once
#include <string>
#include <vector>

class Match {
private:
    int id;
    std::string sport;
    std::string location;
    int maxParticipants;
    std::vector<std::string> participants;
    bool isPublic;

public:
    Match(int id, const std::string& sport, const std::string& location, int maxParticipants, bool isPublic);

    int getId() const;
    std::string getSport() const;
    std::string getLocation() const;
    int getMaxParticipants() const;
    bool getIsPublic() const;
    std::vector<std::string> getParticipants() const;
    int getAvailableSpots() const;

    void addParticipant(const std::string& username);
    bool isUserEnrolled(const std::string& username) const;
};
