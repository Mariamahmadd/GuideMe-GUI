#include <SFML/Graphics.hpp>
#include"files.h"
#include"GuideMe.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include<unordered_map>
#include <iomanip>
using namespace sf;
using namespace std;

int main() {
    files fileReader;
    unordered_map<string, vector<Edge>> graph = fileReader.createGraphFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\TransportationMap.txt");
    GuideMe method;
    RenderWindow window(VideoMode(1000, 800), "Guide Me", Style::Default);
    //loading materials
    Texture backgroundTex;
    if (!backgroundTex.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\background.png")) {
        std::cerr << "Error loading background.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture bfsTex;
    if (!bfsTex.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\bfs.png")) {
        std::cerr << "Error loading bfs.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture dfsTex;
    if (!dfsTex.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\dfs.png")) {
        std::cerr << "Error loading dfs.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture tourbackgroundTex;
    if (!tourbackgroundTex.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\tour.png")) {
        std::cerr << "Error loading background.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture updatebackgroundTex;
    if (!updatebackgroundTex.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\update.png")) {
        std::cerr << "Error loading updatebackground.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture addbackgroundTex;
    if (!addbackgroundTex.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\add.png")) {
        std::cerr << "Error loading addbackground.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture deletebackgroundTex;
    if (!deletebackgroundTex.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\delete.png")) {
        std::cerr << "Error loading deletebackground.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture homeTex;
    if (!homeTex.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\home.png")) {
        std::cerr << "Error loading HOMEPAGE1.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture optionMenu;
    if (!optionMenu.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\option.png")) {
        std::cerr << "Error loading OPTIONMENU.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture startButton;
    if (!startButton.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\getstartedbutton.png")) {
        std::cerr << "Error loading getstartedbutton.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture bfsTraverseButtonTex;
    if (!bfsTraverseButtonTex.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\bfsTraverse.png")) {
        std::cerr << "Error loading bfstraversebutton.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture dfsTraverseButtonTex;
    if (!dfsTraverseButtonTex.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\dfsTraverse.png")) {
        std::cerr << "Error loading dfstraversebutton.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture bfsButton;
    if (!bfsButton.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\bfsbutton.png")) {
        std::cerr << "Error loading bfsbutton.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture dfsButton;
    if (!dfsButton.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\dfsbutton.png")) {
        std::cerr << "Error loading dfsbutton.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture addButton;
    if (!addButton.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\addbutton.png")) {
        std::cerr << "Error loading addbutton.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture addButton2;
    if (!addButton2.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\addbutton2.png")) {
        std::cerr << "Error loading addbutton2.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture updateButton;
    if (!updateButton.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\updatebutton.png")) {
        std::cerr << "Error loading updatebutton.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture updateButton2;
    if (!updateButton2.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\updatebutton2.png")) {
        std::cerr << "Error loading updatebutton2.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture deleteButton;
    if (!deleteButton.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\deletebutton.png")) {
        std::cerr << "Error loading deletebutton.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture deleteButton2;
    if (!deleteButton2.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\deletebutton2.png")) {
        std::cerr << "Error loading deletebutton2.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture tourButton;
    if (!tourButton.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\tourbutton.png")) {
        std::cerr << "Error loading tourbutton.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture tourButton2;
    if (!tourButton2.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\tourbutton2.png")) {
        std::cerr << "Error loading tourbutton2.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture exitButton;
    if (!exitButton.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\exitbutton.png")) {
        std::cerr << "Error loading exitbutton.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture connectedButton;
    if (!connectedButton.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\connectedbutton.png")) {
        std::cerr << "Error loading connectedbutton.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture completeButton;
    if (!completeButton.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\completebutton.png")) {
        std::cerr << "Error loading completebutton.png" << std::endl;
        return EXIT_FAILURE;
    }

    Texture homeIcon;
    if (!homeIcon.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\homeicon.png")) {
        std::cerr << "Error loading homeicon.png" << std::endl;
        return EXIT_FAILURE;
    }

    Font font;
    if (!font.loadFromFile("C:\\Users\\Mariam\\source\\repos\\sfml project\\materials\\roboto.ttf")) {
        std::cerr << "Error loading font." << std::endl;
        return EXIT_FAILURE;
    }

    //sprites
    Sprite sprite(homeTex);
    Sprite bfsTraverseButtonSprite(bfsTraverseButtonTex);
    Sprite dfsTraverseButtonSprite(dfsTraverseButtonTex);
    Sprite startButtonSprite(startButton);
    Sprite bfsButtonSprite(bfsButton);
    Sprite dfsButtonSprite(dfsButton);
    Sprite addButtonSprite(addButton);
    Sprite addButton2Sprite(addButton2);
    Sprite updateButtonSprite(updateButton);
    Sprite updateButton2Sprite(updateButton2);
    Sprite deleteButtonSprite(deleteButton);
    Sprite deleteButton2Sprite(deleteButton2);
    Sprite tourButtonSprite(tourButton);
    Sprite tourButton2Sprite(tourButton2);
    Sprite exitButtonSprite(exitButton);
    Sprite connectedButtonSprite(connectedButton);
    Sprite completeButtonSprite(completeButton);
    Sprite homeIconSprite(homeIcon);

    //setting positions
    homeIconSprite.setPosition(900, 20);
    startButtonSprite.setPosition(384, 472);
    bfsButtonSprite.setPosition(320, 152);
    dfsButtonSprite.setPosition(320, 222);
    addButtonSprite.setPosition(320, 282);
    updateButtonSprite.setPosition(320, 342);
    deleteButtonSprite.setPosition(320, 402);
    tourButtonSprite.setPosition(320, 462);
    completeButtonSprite.setPosition(320, 522);
    connectedButtonSprite.setPosition(320, 582);
    exitButtonSprite.setPosition(320, 642);
    addButton2Sprite.setPosition(400, 602);
    updateButton2Sprite.setPosition(400, 602);
    deleteButton2Sprite.setPosition(400, 602);
    tourButton2Sprite.setPosition(400, 602);
    dfsTraverseButtonSprite.setPosition(400, 602);
    bfsTraverseButtonSprite.setPosition(400, 602);

    //inputs and outputs
    string input;
    Text inputText;
    Text cities;
    Text tourOutput;
    tourOutput.setCharacterSize(22);
    tourOutput.setFont(font);
    tourOutput.setPosition(205, 210);
    cities.setCharacterSize(35);
    cities.setFont(font);
    cities.setPosition(210, 310);
    cities.setFillColor(sf::Color::White);
    inputText.setFont(font);
    inputText.setString(input); // Set initial text (optional)
    inputText.setPosition(340, 247); // Set text position (adjust coordinates)
    string source, destination, transportationType, price, budgetString;
    Text sourceText, destinationText, transportationTypeText, priceText, budgetText;
    sourceText.setFont(font);
    sourceText.setPosition(340, 210);
    destinationText.setFont(font);
    destinationText.setPosition(340, 310);
    transportationTypeText.setFont(font);
    transportationTypeText.setPosition(340, 410);
    priceText.setFont(font);
    priceText.setPosition(340, 510);
    budgetText.setFont(font);
    budgetText.setPosition(340, 410);

    bool isHomePage = true;
    bool isButtonVisible = false;
    bool isButton2Visible = false;
    bool isButtonPressed = false;  // Added variable to track button press
    bool addbuttonvisible = false;
    bool updatebuttonvisible = false;
    bool deletebuttonvisible = false;
    bool tourbuttonvisible = false;
    bool connectedbuttonvisible = false;
    bool completebuttonvisible = false;
    bool bfstraversebuttonvisible = false;
    bool dfstraversebuttonvisible = false;

    bool isSourceActive = true;
    bool isDestinationActive = false;
    bool isTransportationTypeActive = false;
    bool isPriceActive = false;
    bool isbudgetActive = false;
    while (window.isOpen()) {
        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (cities.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            cities.setScale(1.05f, 1.05f); // Scale up
        else
            cities.setScale(1.0f, 1.0f); // Return to original scale

        if (tourOutput.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            tourOutput.setScale(1.05f, 1.05f); // Scale up
        else
            tourOutput.setScale(1.0f, 1.0f); // Return to original scale

        // Check if mouse is over specific sprites and adjust scale accordingly
        if (startButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            startButtonSprite.setScale(1.06f, 1.06f); // Scale up
        else
            startButtonSprite.setScale(1.0f, 1.0f); // Return to original scale

        // Check if mouse is over specific sprites and adjust scale accordingly
        if (homeIconSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            homeIconSprite.setScale(1.05f, 1.05f); // Scale up
        else
            homeIconSprite.setScale(1.0f, 1.0f); // Return to original scale

        if (bfsButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            bfsButtonSprite.setScale(1.04f, 1.04f); // Scale up
        else
            bfsButtonSprite.setScale(1.0f, 1.0f); // Return to original scale

        if (dfsButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            dfsButtonSprite.setScale(1.04f, 1.04f); // Scale up
        else
            dfsButtonSprite.setScale(1.0f, 1.0f); // Return to original scale

        if (addButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            addButtonSprite.setScale(1.04f, 1.04f); // Scale up
        else
            addButtonSprite.setScale(1.0f, 1.0f); // Return to original scale

        if (updateButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            updateButtonSprite.setScale(1.04f, 1.04f); // Scale up
        else
            updateButtonSprite.setScale(1.0f, 1.0f); // Return to original scale

        if (deleteButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            deleteButtonSprite.setScale(1.04f, 1.04f); // Scale up
        else
            deleteButtonSprite.setScale(1.0f, 1.0f); // Return to original scale

        if (connectedButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            connectedButtonSprite.setScale(1.04f, 1.04f); // Scale up
        else
            connectedButtonSprite.setScale(1.0f, 1.0f); // Return to original scale

        if (completeButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            completeButtonSprite.setScale(1.04f, 1.04f); // Scale up
        else
            completeButtonSprite.setScale(1.0f, 1.0f); // Return to original scale

        if (tourButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            tourButtonSprite.setScale(1.04f, 1.04f); // Scale up
        else
            tourButtonSprite.setScale(1.0f, 1.0f); // Return to original scale

        if (bfsTraverseButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            bfsTraverseButtonSprite.setScale(1.04f, 1.04f); // Scale up
        else
            bfsTraverseButtonSprite.setScale(1.0f, 1.0f); // Return to original scale

        if (dfsTraverseButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            dfsTraverseButtonSprite.setScale(1.04f, 1.04f); // Scale up
        else
            dfsTraverseButtonSprite.setScale(1.0f, 1.0f); // Return to original scale

        if (addButton2Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            addButton2Sprite.setScale(1.06f, 1.06f); // Scale up
        else
            addButton2Sprite.setScale(1.0f, 1.0f); // Return to original scale
        if (updateButton2Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            updateButton2Sprite.setScale(1.06f, 1.06f); // Scale up
        else
            updateButton2Sprite.setScale(1.0f, 1.0f); // Return to original scale
        if (deleteButton2Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            deleteButton2Sprite.setScale(1.06f, 1.06f); // Scale up
        else
            deleteButton2Sprite.setScale(1.0f, 1.0f); // Return to original scale

        if (tourButton2Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            tourButton2Sprite.setScale(1.06f, 1.06f); // Scale up
        else
            deleteButton2Sprite.setScale(1.0f, 1.0f); // Return to original scale
        if (exitButtonSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            exitButtonSprite.setScale(1.04f, 1.04f); // Scale up
        else
            exitButtonSprite.setScale(1.0f, 1.0f); // Return to original scale

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::TextEntered && (bfstraversebuttonvisible || dfstraversebuttonvisible)) {
                // Handle text input only when the Traverse buttons are visible
                if (event.text.unicode < 128) { // Check if the entered character is an ASCII character
                    if (event.text.unicode == 8) { // Backspace key
                        if (!input.empty()) { // Check if input string is not empty
                            input.pop_back(); // Remove the last character
                        }
                    }
                    else {
                        input += static_cast<char>(event.text.unicode); // Add the entered character to the input string
                    }
                    inputText.setString(input); // Update the input text
                }
            }

            if (event.type == Event::TextEntered && (addbuttonvisible || updatebuttonvisible)) {
                // Handle text input only when the Traverse buttons are visible
                if (event.text.unicode < 128) { // Check if the entered character is an ASCII character
                    if (event.text.unicode < 128) {
                        if (event.text.unicode == 13) { // Enter key
                            if (isSourceActive) {
                                isSourceActive = false;
                                isDestinationActive = true;
                            }
                            else if (isDestinationActive) {
                                isDestinationActive = false;
                                isTransportationTypeActive = true;
                            }
                            else if (isTransportationTypeActive) {
                                isTransportationTypeActive = false;
                                isPriceActive = true;
                            }
                        }
                        else if (event.text.unicode == 8) { // Backspace key
                            if (isSourceActive && !source.empty()) {
                                source.pop_back();
                            }
                            else if (isDestinationActive && !destination.empty()) {
                                destination.pop_back();
                            }
                            else if (isTransportationTypeActive && !transportationType.empty()) {
                                transportationType.pop_back();
                            }
                            else if (isPriceActive && !price.empty()) {
                                price.pop_back();
                            }
                        }
                        else {
                            if (isSourceActive) {
                                source += static_cast<char>(event.text.unicode);
                            }
                            else if (isDestinationActive) {
                                destination += static_cast<char>(event.text.unicode);
                            }
                            else if (isTransportationTypeActive) {
                                transportationType += static_cast<char>(event.text.unicode);
                            }
                            else if (isPriceActive) {
                                // Check if the entered character is a digit
                                if (isdigit(event.text.unicode)) {
                                    price += static_cast<char>(event.text.unicode);
                                }
                            }
                        }

                        // Update the text fields
                        sourceText.setString(source);
                        destinationText.setString(destination);
                        transportationTypeText.setString(transportationType);
                        priceText.setString(price);
                    }
                }
            }
            if (event.type == Event::TextEntered && deletebuttonvisible) {
                // Handle text input only when the Traverse buttons are visible
                if (event.text.unicode < 128) { // Check if the entered character is an ASCII character
                    if (event.text.unicode < 128) {
                        if (event.text.unicode == 13) { // Enter key
                            if (isSourceActive) {
                                isSourceActive = false;
                                isDestinationActive = true;
                            }
                            else if (isDestinationActive) {
                                isDestinationActive = false;
                                isTransportationTypeActive = true;
                            }
                        }
                        else if (event.text.unicode == 8) { // Backspace key
                            if (isSourceActive && !source.empty()) {
                                source.pop_back();
                            }
                            else if (isDestinationActive && !destination.empty()) {
                                destination.pop_back();
                            }
                            else if (isTransportationTypeActive && !transportationType.empty()) {
                                transportationType.pop_back();
                            }
                        }
                        else {
                            if (isSourceActive) {
                                source += static_cast<char>(event.text.unicode);
                            }
                            else if (isDestinationActive) {
                                destination += static_cast<char>(event.text.unicode);
                            }
                            else if (isTransportationTypeActive) {
                                transportationType += static_cast<char>(event.text.unicode);
                            }
                        }

                        // Update the text fields
                        sourceText.setString(source);
                        destinationText.setString(destination);
                        transportationTypeText.setString(transportationType);
                    }
                }
            }
            if (event.type == Event::TextEntered && tourbuttonvisible) {
                // Handle text input only when the Traverse buttons are visible
                if (event.text.unicode < 128) { // Check if the entered character is an ASCII character
                    if (event.text.unicode == 13) { // Enter key
                        if (isSourceActive) {
                            isSourceActive = false;
                            isDestinationActive = true;
                        }
                        else if (isDestinationActive) {
                            isDestinationActive = false;
                            isbudgetActive = true;
                        }
                    }
                    else if (event.text.unicode == 8) { // Backspace key
                        if (isSourceActive && !source.empty()) {
                            source.pop_back();
                        }
                        else if (isDestinationActive && !destination.empty()) {
                            destination.pop_back();
                        }
                        else if (isbudgetActive && !budgetString.empty()) {
                            budgetString.pop_back();
                        }
                    }
                    else {
                        if (isSourceActive) {
                            source += static_cast<char>(event.text.unicode);
                        }
                        else if (isDestinationActive) {
                            destination += static_cast<char>(event.text.unicode);
                        }
                        else if (isbudgetActive) {
                            // Check if the entered character is a digit
                            if (isdigit(event.text.unicode)) {
                                budgetString += static_cast<char>(event.text.unicode);
                            }
                        }
                    }

                    // Update the text fields
                    sourceText.setString(source);
                    destinationText.setString(destination);
                    budgetText.setString(budgetString);
                }
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2i mousePos = Mouse::getPosition(window);
                if (homeIconSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    isHomePage = true;
                    sprite.setTexture(homeTex);
                    isButtonVisible = false;
                    isButton2Visible = false;
                    isButtonPressed = false; // Reset button press state
                    addbuttonvisible = false;  // Reset addButton2 visibility
                    updatebuttonvisible = false; // Reset updateButton2 visibility
                    deletebuttonvisible = false; // Reset deleteButton2 visibility
                    tourbuttonvisible = false;  // Reset tourButton2 visibility
                    connectedbuttonvisible = false;
                    completebuttonvisible = false;
                    bfstraversebuttonvisible = false;
                    dfstraversebuttonvisible = false;
                    cities.setString("");
                    tourOutput.setString("");
                    // Clear all input strings
                    input.clear();
                    source.clear();
                    destination.clear();
                    transportationType.clear();
                    price.clear();
                    budgetString.clear();
                    // Update text fields
                    inputText.setString(input);
                    sourceText.setString(source);
                    destinationText.setString(destination);
                    transportationTypeText.setString(transportationType);
                    priceText.setString(price);
                    budgetText.setString(budgetString);
                }

                else {
                    if (isHomePage) {
                        if (startButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            isHomePage = false;
                            sprite.setTexture(optionMenu);
                            isButtonVisible = true;
                        }
                    }
                    else {
                        if (isButtonVisible) {
                            if (bfsButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                isButtonPressed = true;  // Set button press state
                                bfstraversebuttonvisible = true;
                                sprite.setTexture(bfsTex);
                                isButtonVisible = false;
                            }
                            else if (dfsButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                isButtonPressed = true;
                                dfstraversebuttonvisible = true;
                                sprite.setTexture(dfsTex);
                                isButtonVisible = false;
                            }
                            else if (addButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                isButtonPressed = true;
                                addbuttonvisible = true;
                                sprite.setTexture(addbackgroundTex);
                                isButtonVisible = false;
                            }
                            else if (updateButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                isButtonPressed = true;
                                updatebuttonvisible = true;
                                sprite.setTexture(updatebackgroundTex);
                                isButtonVisible = false;
                            }
                            else if (deleteButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                isButtonPressed = true;
                                deletebuttonvisible = true;
                                sprite.setTexture(deletebackgroundTex);
                                isButtonVisible = false;
                            }
                            else if (tourButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                isButtonPressed = true;
                                tourbuttonvisible = true;
                                sprite.setTexture(tourbackgroundTex);
                                isButtonVisible = false;
                            }
                            else if (connectedButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                isButtonPressed = true;
                                connectedbuttonvisible = true;
                                sprite.setTexture(backgroundTex);
                                isButtonVisible = false;
                            }
                            else if (completeButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                isButtonPressed = true;
                                completebuttonvisible = true;
                                sprite.setTexture(backgroundTex);
                                isButtonVisible = false;
                            }
                            else if (exitButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                isButtonPressed = true;
                                window.close();
                            }
                        }
                        if (addbuttonvisible && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                            if (addButton2Sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                addbuttonvisible = false;  // Hide addButton2 after action
                                sprite.setTexture(backgroundTex);
                                int priceValue = std::stoi(price);
                                string result = method.addEdge(graph, source, destination, transportationType, priceValue);
                                cities.setString(result);
                                source.clear();
                                destination.clear();
                                transportationType.clear();
                                price.clear();
                                isSourceActive = true;
                                isDestinationActive = false;
                                isTransportationTypeActive = false;
                                isPriceActive = false;
                                // Update the text fields
                                sourceText.setString(source);
                                destinationText.setString(destination);
                                transportationTypeText.setString(transportationType);
                                priceText.setString(price);
                            }
                        }
                        else if (updatebuttonvisible && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                            if (updateButton2Sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                updatebuttonvisible = false;  // Hide addButton2 after action
                                sprite.setTexture(backgroundTex);
                                int priceValue = stoi(price);
                                string result = method.updateEdge(graph, source, destination, transportationType, priceValue);
                                cities.setString(result);
                                source.clear();
                                destination.clear();
                                transportationType.clear();
                                price.clear();
                                isSourceActive = true;
                                isDestinationActive = false;
                                isTransportationTypeActive = false;
                                isPriceActive = false;
                                // Update the text fields
                                sourceText.setString(source);
                                destinationText.setString(destination);
                                transportationTypeText.setString(transportationType);
                                priceText.setString(price);
                            }
                        }
                        else if (deletebuttonvisible && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                            if (deleteButton2Sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                cout << "deleting data..." << endl;  // Print message on click
                                deletebuttonvisible = false;  // Hide addButton2 after action
                                sprite.setTexture(backgroundTex);
                                string result = method.deleteEdge(graph, source, destination, transportationType);
                                cities.setString(result);
                                source.clear();
                                destination.clear();
                                transportationType.clear();
                                isSourceActive = true;
                                isDestinationActive = false;
                                isTransportationTypeActive = false;
                                // Update the text fields
                                sourceText.setString(source);
                                destinationText.setString(destination);
                                transportationTypeText.setString(transportationType);
                            }
                        }
                        else if (tourbuttonvisible && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                            if (tourButton2Sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                cout << "retreiving data..." << endl;  // Print message on click
                                tourbuttonvisible = false;  // Hide addButton2 after action
                                sprite.setTexture(backgroundTex);
                                int budget = std::stoi(budgetString);
                                string result = method.findAllPaths(source, destination, budget, graph);
                                tourOutput.setString(result);
                                source.clear();
                                destination.clear();
                                budgetString.clear();
                                isSourceActive = true;
                                isDestinationActive = false;
                                isbudgetActive = false;
                                // Update the text fields
                                sourceText.setString(source);
                                destinationText.setString(destination);
                                budgetText.setString(budgetString);
                            }
                        }
                        else if (dfstraversebuttonvisible && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                            if (dfsTraverseButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                dfstraversebuttonvisible = false;
                                sprite.setTexture(backgroundTex);
                                string result = method.DFS(graph, input); // Get DFS result
                                cities.setString(result); // Display result in the cities text object                              
                                input = "";
                                inputText.setString(input);

                            }
                        }
                        else if (bfstraversebuttonvisible && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                            if (bfsTraverseButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                bfstraversebuttonvisible = false;
                                sprite.setTexture(backgroundTex);
                                // Call BFS method with the graph and starting city
                                string result = method.BFS(graph, input);
                                cities.setString(result); // Display BFS result 
                                input = "";
                                inputText.setString(input);
                            }
                        }
                        else if (completebuttonvisible && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                            if (completeButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                // Call the isCompleteMap function to check if the graph is complete
                                string result = method.isCompleteMap(graph);

                                // Display the result on the screen
                                cities.setString(result);
                                completebuttonvisible = false; // Hide the complete button after displaying the result
                                sprite.setTexture(backgroundTex); // Set the background sprite
                            }
                        }
                        else if (connectedbuttonvisible && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                            if (connectedButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                connectedbuttonvisible = false; // Hide the button after click
                                // Call the isConnectedMap method to check graph connectivity
                                string connectivityResult = method.isConnectedMap(graph);
                                // Update the cities text object to display the connectivity result
                                cities.setString(connectivityResult);
                            }
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(sprite);  // Only draw the currently desired image
        if (isHomePage) {
            window.draw(startButtonSprite);
        }
        else if (isButtonVisible) {
            window.draw(bfsButtonSprite);
            window.draw(dfsButtonSprite);
            window.draw(addButtonSprite);
            window.draw(updateButtonSprite);
            window.draw(deleteButtonSprite);
            window.draw(tourButtonSprite);
            window.draw(connectedButtonSprite);
            window.draw(completeButtonSprite);
            window.draw(exitButtonSprite);
        }
        else if (addbuttonvisible) {
            window.draw(addButton2Sprite);
        }
        else if (updatebuttonvisible) {
            window.draw(updateButton2Sprite);
        }
        else if (deletebuttonvisible) {
            window.draw(deleteButton2Sprite);
        }
        else if (tourbuttonvisible) {
            window.draw(tourButton2Sprite);
        }
        else if (dfstraversebuttonvisible) {
            window.draw(dfsTraverseButtonSprite);
        }
        else if (bfstraversebuttonvisible) {
            window.draw(bfsTraverseButtonSprite);
        }

        window.draw(homeIconSprite);
        window.draw(inputText);
        window.draw(sourceText);
        window.draw(destinationText);
        window.draw(transportationTypeText);
        window.draw(priceText);
        window.draw(budgetText);
        window.draw(cities);
        window.draw(tourOutput);

        window.display();

    }
    return 0;
}