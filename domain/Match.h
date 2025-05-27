//Match.h

#pragma once
#include <string>
#include <vector>
#include "Entity.h"

class Match : public Entity {
private:
    std::string sport;
    std::string location;
    int maxParticipants;
    std::vector<std::string> participants;
    bool isPublic;
    std::vector<std::string> spectators;

public:
    Match(int id, const std::string& sport, const std::string& location, int maxParticipants, bool isPublic);

    int getId() const override;  // din Entity
    std::string getSport() const;
    std::string getLocation() const;
    int getMaxParticipants() const;
    bool getIsPublic() const;
    std::vector<std::string> getParticipants() const;
    int getAvailableSpots() const;

    void addParticipant(const std::string& username);
    bool isUserEnrolled(const std::string& username) const;

    void addSpectator(const std::string& name);
    std::vector<std::string> getSpectators() const;

    std::string getInfo() const override;
};
