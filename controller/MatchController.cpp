//
// Created by andre on 12/05/2025.
//
#include "MatchController.h"

MatchController::MatchController(MatchRepository& repo) : repo(repo) {}

void MatchController::addMatch(const std::string& sport, const std::string& location, int capacity, bool isPublic) {
    repo.addMatch(sport, location, capacity, isPublic);
}

std::vector<Match> MatchController::getAllMatches() const {
    return repo.getAllMatches();
}

std::vector<Match> MatchController::searchBySport(const std::string& sport) const {
    return repo.searchBySport(sport);
}

bool MatchController::enrollUserToMatch(int matchId, const std::string& username) {
    Match* match = repo.findById(matchId);
    if (match && match->getIsPublic() && match->getAvailableSpots() > 0 && !match->isUserEnrolled(username)) {
        match->addParticipant(username);
        return true;
    }
    return false;
}

std::optional<int> MatchController::getAvailableSpots(int matchId) const {
    Match* match = repo.findById(matchId);
    if (match) {
        return match->getAvailableSpots();
    }
    return std::nullopt;
    }
Match* MatchController::getMatchById(int id) {
    for (auto& match : repo.getMatches()) {
        if (match.getId() == id)
            return &match;
    }
    return nullptr;
}
