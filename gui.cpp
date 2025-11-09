// //
// // Created by Timothy Wang on 11/7/25.
// //
// #include <iostream>
// #include <fstream>
// #include <map>
// #include <vector>
// #include <sstream>
// #include "Graph.h"
// #include <SFML/Graphics.hpp>
// using namespace std;
//
//
// void startGUI(const vector<string>& cities){
//     sf::RenderWindow startWindow(sf::VideoMode(1200,900), "Destination Cost");
//     startWindow.setFramerateLimit(60);
//
//     sf::Font font;
//     if (!font.loadFromFile("../ARIAL.TTF")) {
//         cout << "Error loading font" << endl;
//     }
//
//     //algorithm select boxes
//     sf::Text usingText("Using: ", font, 20);
//     usingText.setFillColor(sf::Color(160, 200, 200));
//     usingText.setPosition(805,55);
//
//     sf::RectangleShape algorithmSelect(sf::Vector2f(230,40));
//     algorithmSelect.setFillColor(sf::Color(30, 35, 40));
//     algorithmSelect.setOutlineColor(sf::Color(160, 200, 200));
//     algorithmSelect.setOutlineThickness(2);
//     algorithmSelect.setPosition(875,50);
//
//     sf::Text text("Select Algorithm", font, 20);
//     text.setPosition(885,55);
//     text.setFillColor(sf::Color(160, 200, 200));
//
//     sf::RectangleShape dijkstraOption(sf::Vector2f(230,40));
//     dijkstraOption.setFillColor(sf::Color(30, 35, 40));
//     dijkstraOption.setOutlineColor(sf::Color(160, 200, 200));
//     dijkstraOption.setOutlineThickness(2);
//     dijkstraOption.setPosition(875,90);
//
//     sf::Text dijkstraText("Dijkstra's Algorithm", font, 16);
//     dijkstraText.setPosition(885,97);
//     dijkstraText.setFillColor(sf::Color(160, 200, 200));
//
//     sf::RectangleShape bellmanFordOption(sf::Vector2f(230,40));
//     bellmanFordOption.setFillColor(sf::Color(30, 35, 40));
//     bellmanFordOption.setOutlineColor(sf::Color(160, 200, 200));
//     bellmanFordOption.setOutlineThickness(2);
//     bellmanFordOption.setPosition(875,130);
//
//     sf::Text bellmanFordText("Bellman Ford Algorithm", font, 16);
//     bellmanFordText.setFillColor(sf::Color(160, 200, 200));
//     bellmanFordText.setPosition(885,137);
//
//     bool algorithmDropDown = false;
//     string selected = "";
//
//
//     // city origin boxes
//     sf::Text toText("From: ", font, 20);
//     toText.setPosition(50, 55);
//     toText.setFillColor(sf::Color(160, 200, 200));
//
//     sf::RectangleShape originSearch(sf::Vector2f(250,40));
//     originSearch.setPosition(115,50);
//     originSearch.setFillColor(sf::Color(30, 35, 40));
//     originSearch.setOutlineColor(sf::Color(160, 200, 200));
//     originSearch.setOutlineThickness(2);
//
//     sf::Text searchTextOrigin("Select Origin City", font, 20);
//     searchTextOrigin.setFillColor(sf::Color(160, 200, 200));
//     searchTextOrigin.setPosition(125, 55);
//
//     vector<string> searchOriginCities = cities;
//     string inputCities;
//     bool originDropDown = false;
//     bool originTypeInput = false;
//
//
//
//     // city destination boxes
//     sf::Text fromText("To: ", font, 20);
//     fromText.setPosition(450, 55);
//     fromText.setFillColor(sf::Color(160, 200, 200));
//
//
//     sf::RectangleShape destinationSearch(sf::Vector2f(250,40));
//     destinationSearch.setPosition(490,50);
//     destinationSearch.setFillColor(sf::Color(30, 35, 40));
//     destinationSearch.setOutlineColor(sf::Color(160, 200, 200));
//     destinationSearch.setOutlineThickness(2);
//
//     sf::Text searchTextDestination("Select Destination City", font, 20);
//     searchTextDestination.setFillColor(sf::Color(160, 200, 200));
//     searchTextDestination.setPosition(500, 55);
//
//     vector<string> searchDestinationCities = cities;
//     string inputDestinationCities;
//     bool destinationDropDown = false;
//     bool destinationTypeInput = false;
//
//
//     while (startWindow.isOpen()) {
//         sf::Event event;
//         while (startWindow.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 startWindow.close();
//             sf::Vector2f mouse(sf::Mouse::getPosition(startWindow));
//
//             //opens dd boxes
//             if (event.type == sf::Event::MouseButtonPressed) {
//                 // algorithm select dd
//                 if (algorithmSelect.getGlobalBounds().contains(mouse)) {
//                     algorithmDropDown = !algorithmDropDown;
//
//                 }else if (algorithmDropDown && dijkstraOption.getGlobalBounds().contains(mouse)) {
//                     selected = "Dijkstra";
//                     text.setString("Dijkstra's Algorithm");
//                     algorithmDropDown = false;
//
//                 } else if (algorithmDropDown && bellmanFordOption.getGlobalBounds().contains(mouse)) {
//                     selected = "Bellman Ford";
//                     text.setString("Bellman Ford Algorithm");
//                     algorithmDropDown = false;
//                 }
//                 else {
//                     algorithmDropDown = false;
//                 }
//
//                 //origin select dd
//                 if (originSearch.getGlobalBounds().contains(mouse)) {
//                     originTypeInput = true;
//                     originDropDown = !originDropDown;
//
//                 }else if (originDropDown){
//                     float y = 90;
//                     for (const auto& city : searchOriginCities) {
//                         if (sf::FloatRect(115, y, 250, 30).contains(mouse)) {
//                             inputCities = city;
//                             searchTextOrigin.setString(city);
//                             originDropDown = false;
//                             originTypeInput = false;
//                             break;
//                         }
//                         y += 30;
//                     }
//                 }
//
//             // destination search dd
//                 if (destinationSearch.getGlobalBounds().contains(mouse)) {
//                     destinationTypeInput = true;
//                     destinationDropDown = !destinationDropDown;
//                 }else if (destinationDropDown){
//                     float y = 90;
//                     for (const auto& destinationCity : searchDestinationCities) {
//                         if (sf::FloatRect(490, y, 250, 30).contains(mouse)) {
//                             inputDestinationCities = destinationCity;
//                             searchTextDestination.setString(destinationCity);
//                             destinationDropDown = false;
//                             destinationTypeInput = false;
//                             break;
//                         }
//                         y += 30;
//                     }
//                 }
//             }
//
//
//
//             //algorithm highlight hover
//             if (algorithmDropDown == true) {
//                 if (dijkstraOption.getGlobalBounds().contains(mouse))
//                     dijkstraOption.setFillColor(sf::Color(55, 90, 90));
//                 else {
//                     dijkstraOption.setFillColor(sf::Color(30, 35, 40));
//                 }
//
//                 if (bellmanFordOption.getGlobalBounds().contains(mouse))
//                     bellmanFordOption.setFillColor(sf::Color(55, 90, 90));
//                 else {
//                     bellmanFordOption.setFillColor(sf::Color(30, 35, 40));
//                 }
//             }
//
//             // origin input text
//             if (originTypeInput && event.type == sf::Event::TextEntered) {
//                 if (event.text.unicode == 8 && !inputCities.empty()) {
//                     inputCities.pop_back();
//                 } else if (event.text.unicode >= 32 && event.text.unicode < 128) {
//                     inputCities += static_cast<char>(event.text.unicode);
//                 }
//
//                 searchTextOrigin.setString(inputCities);
//                 searchOriginCities.clear();
//
//                 // case insensitive
//                 string OinputLowercase = inputCities;
//                 transform(OinputLowercase.begin(), OinputLowercase.end(), OinputLowercase.begin(), ::tolower);
//
//                 //refines dropdown as char entered
//                 for (const auto& city : cities) {
//                     string Olowercase = city;
//                     transform(Olowercase.begin(), Olowercase.end(), Olowercase.begin(), ::tolower);
//                     if (OinputLowercase.empty() || Olowercase.find(OinputLowercase) != string::npos)
//                         searchOriginCities.push_back(city);
//                 }
//
//                 if (searchOriginCities.empty() && OinputLowercase.empty())
//                     searchOriginCities = cities;
//             }
//
//             // destination input text
//             if (destinationTypeInput && event.type == sf::Event::TextEntered) {
//                 if (event.text.unicode == 8 && !inputDestinationCities.empty()) {
//                     inputDestinationCities.pop_back();
//                 } else if (event.text.unicode >= 32 && event.text.unicode < 128) {
//                     inputDestinationCities += static_cast<char>(event.text.unicode);
//                 }
//
//                 searchTextDestination.setString(inputDestinationCities);
//
//                 searchDestinationCities.clear();
//                 string DinputLowercase = inputDestinationCities;
//
//                 // maybe fix this ??
//                 transform(DinputLowercase.begin(), DinputLowercase.end(), DinputLowercase.begin(), ::tolower);
//
//                 for (const auto& destinationCity : cities) {
//                     string Dlowercase = destinationCity;
//                     transform(Dlowercase.begin(), Dlowercase.end(), Dlowercase.begin(), ::tolower);
//                     if (DinputLowercase.empty() || Dlowercase.find(DinputLowercase) != string::npos)
//                         searchDestinationCities.push_back(destinationCity);
//                 }
//
//                 if (searchDestinationCities.empty() && DinputLowercase.empty())
//                     searchDestinationCities = cities;
//             }
//         }
//
//
//         startWindow.clear(sf::Color(30, 35, 40));
//         startWindow.draw(toText);
//         startWindow.draw(fromText);
//         startWindow.draw(usingText);
//
//         startWindow.draw(algorithmSelect);
//         startWindow.draw(text);
//         if (algorithmDropDown == true) {
//             startWindow.draw(dijkstraOption);
//             startWindow.draw(dijkstraText);
//             startWindow.draw(bellmanFordOption);
//             startWindow.draw(bellmanFordText);
//         }
//
//         startWindow.draw(originSearch);
//         startWindow.draw(searchTextOrigin);
//
//         //creating the dd that changes as user types
//         if (originDropDown && !searchOriginCities.empty()) {
//             float y = 90;
//             int shown = 0;
//             for (const auto& name : searchOriginCities) {
//                 //only shows 10 results
//                 if (shown >= 10) break;
//
//                 sf::RectangleShape cityOption(sf::Vector2f(250,30));
//                 cityOption.setPosition(115, y);
//                 cityOption.setFillColor(sf::Color(30, 35, 40));
//                 cityOption.setOutlineColor(sf::Color(160, 200, 200));
//                 cityOption.setOutlineThickness(2);
//
//                 sf::Text cityText(name, font, 16);
//                 cityText.setFillColor(sf::Color(160, 200, 200));
//                 cityText.setPosition(125, y + 4);
//
//                 startWindow.draw(cityOption);
//                 startWindow.draw(cityText);
//
//                 y += 30;
//                 shown++;
//             }
//         }
//
//         startWindow.draw(destinationSearch);
//         startWindow.draw(searchTextDestination);
//
//         if (destinationDropDown && !searchDestinationCities.empty()) {
//             float y = 90;
//             int shown = 0;
//             for (const auto& name : searchDestinationCities) {
//                 if (shown >= 10) break;
//
//                 sf::RectangleShape cityOptionD(sf::Vector2f(250,30));
//                 cityOptionD.setPosition(490, y);
//                 cityOptionD.setFillColor(sf::Color(30, 35, 40));
//                 cityOptionD.setOutlineColor(sf::Color(160, 200, 200));
//                 cityOptionD.setOutlineThickness(2);
//
//                 sf::Text cityTextD(name, font, 16);
//                 cityTextD.setFillColor(sf::Color(160, 200, 200));
//                 cityTextD.setPosition(500, y + 4);
//
//                 startWindow.draw(cityOptionD);
//                 startWindow.draw(cityTextD);
//
//                 y += 30;
//                 shown++;
//             }
//         }
//
//         startWindow.display();
//     }
// }

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <tuple>
#include <chrono>
#include "Graph.h"
#include "Dijkstra.h"
#include "Astar.h"
#include <iomanip>
#include <sstream>

using namespace std;

void startGUI(Graph& graph, const vector<string>& cities) {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Destination Cost");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("../ARIAL.TTF")) {
        cout << "Error loading font" << endl;
    }

    // ===== Labels =====
    sf::Text fromText("From:", font, 24);
    fromText.setFillColor(sf::Color(160, 200, 200));
    fromText.setPosition(100, 100);

    sf::Text toText("To:", font, 24);
    toText.setFillColor(sf::Color(160, 200, 200));
    toText.setPosition(100, 200);

    sf::Text algoText("Algorithm:", font, 24);
    algoText.setFillColor(sf::Color(160, 200, 200));
    algoText.setPosition(100, 300);

    // ===== Input Boxes =====
    sf::RectangleShape fromBox(sf::Vector2f(400, 40));
    fromBox.setPosition(200, 95);
    fromBox.setFillColor(sf::Color(30, 35, 40));
    fromBox.setOutlineColor(sf::Color(160, 200, 200));
    fromBox.setOutlineThickness(2);

    sf::RectangleShape toBox(sf::Vector2f(400, 40));
    toBox.setPosition(200, 195);
    toBox.setFillColor(sf::Color(30, 35, 40));
    toBox.setOutlineColor(sf::Color(160, 200, 200));
    toBox.setOutlineThickness(2);

    sf::RectangleShape algoBox(sf::Vector2f(400, 40));
    algoBox.setPosition(200, 295);
    algoBox.setFillColor(sf::Color(30, 35, 40));
    algoBox.setOutlineColor(sf::Color(160, 200, 200));
    algoBox.setOutlineThickness(2);

    // ===== Input Texts =====
    sf::Text fromInput("", font, 20);
    fromInput.setFillColor(sf::Color::White);
    fromInput.setPosition(210, 100);

    sf::Text toInput("", font, 20);
    toInput.setFillColor(sf::Color::White);
    toInput.setPosition(210, 200);

    sf::Text algoInput("Select Algorithm", font, 20);
    algoInput.setFillColor(sf::Color(160, 200, 200));
    algoInput.setPosition(210, 300);

    // ===== Dropdown =====
    bool typingFrom = false;
    bool typingTo = false;
    bool algoDropdownOpen = false;
    string selectedAlgorithm = "";

    sf::RectangleShape dijkstraOption(sf::Vector2f(400, 40));
    dijkstraOption.setPosition(200, 335);
    dijkstraOption.setFillColor(sf::Color(30, 35, 40));
    dijkstraOption.setOutlineColor(sf::Color(160, 200, 200));
    dijkstraOption.setOutlineThickness(2);

    sf::Text dijkstraText("Dijkstra's Algorithm", font, 20);
    dijkstraText.setFillColor(sf::Color(160, 200, 200));
    dijkstraText.setPosition(210, 340);

    sf::RectangleShape aStarOption(sf::Vector2f(400, 40));
    aStarOption.setPosition(200, 375);
    aStarOption.setFillColor(sf::Color(30, 35, 40));
    aStarOption.setOutlineColor(sf::Color(160, 200, 200));
    aStarOption.setOutlineThickness(2);

    sf::Text aStarText("A* Algorithm", font, 20);
    aStarText.setFillColor(sf::Color(160, 200, 200));
    aStarText.setPosition(210, 380);

    // ===== Calculate Button =====
    sf::RectangleShape calcButton(sf::Vector2f(200, 50));
    calcButton.setPosition(500, 500);
    calcButton.setFillColor(sf::Color(60, 120, 100));
    calcButton.setOutlineThickness(2);
    calcButton.setOutlineColor(sf::Color(160, 200, 200));

    sf::Text calcText("CALCULATE", font, 24);
    calcText.setFillColor(sf::Color::White);
    calcText.setPosition(530, 510);

    // ===== Result Texts =====
    sf::Text resultText("", font, 22);
    resultText.setFillColor(sf::Color::White);
    resultText.setPosition(100, 600);

    sf::Text timeText("", font, 20);
    timeText.setFillColor(sf::Color(160, 200, 200));
    timeText.setPosition(100, 640);

    // ===== Main Loop =====
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            sf::Vector2f mouse(sf::Mouse::getPosition(window));

            // --- Mouse Clicks ---
            if (event.type == sf::Event::MouseButtonPressed) {
                typingFrom = fromBox.getGlobalBounds().contains(mouse);
                typingTo = toBox.getGlobalBounds().contains(mouse);

                if (algoBox.getGlobalBounds().contains(mouse))
                    algoDropdownOpen = !algoDropdownOpen;
                else if (algoDropdownOpen && dijkstraOption.getGlobalBounds().contains(mouse)) {
                    selectedAlgorithm = "Dijkstra";
                    algoInput.setString("Dijkstra's Algorithm");
                    algoDropdownOpen = false;
                } else if (algoDropdownOpen && aStarOption.getGlobalBounds().contains(mouse)) {
                    selectedAlgorithm = "A*";
                    algoInput.setString("A* Algorithm");
                    algoDropdownOpen = false;
                } else
                    algoDropdownOpen = false;

                // === Calculate Button ===
                if (calcButton.getGlobalBounds().contains(mouse)) {
                    string src = fromInput.getString().toAnsiString();
                    string dest = toInput.getString().toAnsiString();

                    if (src.empty() || dest.empty() || selectedAlgorithm.empty()) {
                        resultText.setString("Please enter both cities and select algorithm!");
                        timeText.setString("");
                    } else {
                        map<City, vector<Edge>> edges = graph.getEdges();
                        City srcObj, destObj;
                        bool foundSrc = false, foundDest = false;

                        for (auto &pair : edges) {
                            if (pair.first.name == src) {
                                srcObj = pair.first;
                                foundSrc = true;
                            }
                            if (pair.first.name == dest) {
                                destObj = pair.first;
                                foundDest = true;
                            }
                        }

                        if (!foundSrc || !foundDest) {
                            resultText.setString("One or both cities not found in dataset!");
                            timeText.setString("");
                        } else {
                            double cost = 0.0;
                            double ms = 0.0;

                            if (selectedAlgorithm == "Dijkstra") {
                                Dijkstra dij;
                                auto start = chrono::high_resolution_clock::now();
                                auto dijResult = dij.dijkstraShortestPath(graph, srcObj);
                                auto end = chrono::high_resolution_clock::now();
                                cost = dijResult[destObj];
                                ms = chrono::duration<double, milli>(end - start).count();
                            } else if (selectedAlgorithm == "A*") {
                                Astar astar;
                                vector<City> path;
                                auto start = chrono::high_resolution_clock::now();
                                auto result = astar.astarShortestPath(graph, srcObj, destObj, path);
                                auto end = chrono::high_resolution_clock::now();
                                cost = result[destObj];
                                ms = chrono::duration<double, milli>(end - start).count();
                            }

                            std::ostringstream ss;
                            ss << std::fixed << std::setprecision(2) << cost;
                            resultText.setString("Minimum delivery cost: $" + ss.str());
                            timeText.setString("Execution time: " + to_string(ms) + " ms");
                        }
                    }
                }
            }

            // --- Text Input ---
            if (event.type == sf::Event::TextEntered) {
                if (typingFrom) {
                    if (event.text.unicode == 8 && !fromInput.getString().isEmpty()) {
                        string s = fromInput.getString();
                        s.pop_back();
                        fromInput.setString(s);
                    } else if (event.text.unicode >= 32 && event.text.unicode < 128) {
                        string s = fromInput.getString();
                        s += static_cast<char>(event.text.unicode);
                        fromInput.setString(s);
                    }
                } else if (typingTo) {
                    if (event.text.unicode == 8 && !toInput.getString().isEmpty()) {
                        string s = toInput.getString();
                        s.pop_back();
                        toInput.setString(s);
                    } else if (event.text.unicode >= 32 && event.text.unicode < 128) {
                        string s = toInput.getString();
                        s += static_cast<char>(event.text.unicode);
                        toInput.setString(s);
                    }
                }
            }

            if (calcButton.getGlobalBounds().contains(mouse))
                calcButton.setFillColor(sf::Color(80, 150, 130));
            else
                calcButton.setFillColor(sf::Color(60, 120, 100));
        }

        // --- Draw GUI ---
        window.clear(sf::Color(30, 35, 40));
        window.draw(fromText);
        window.draw(toText);
        window.draw(algoText);
        window.draw(fromBox);
        window.draw(toBox);
        window.draw(algoBox);
        window.draw(fromInput);
        window.draw(toInput);
        window.draw(algoInput);

        if (algoDropdownOpen) {
            window.draw(dijkstraOption);
            window.draw(dijkstraText);
            window.draw(aStarOption);
            window.draw(aStarText);
        }

        window.draw(calcButton);
        window.draw(calcText);
        window.draw(resultText);
        window.draw(timeText);
        window.display();
    }
}