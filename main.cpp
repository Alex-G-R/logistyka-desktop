#include "FRSGUI/FRSGUI.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

constexpr int WINDOW_HEIGHT = 1080;
constexpr int WINDOW_WIDTH = 1920;

constexpr float CENA_ZA_KILOMETR = 2.f;
constexpr int CENA_KONSULTACJA = 400;
constexpr int CENA_BUDOWA = 20000;
constexpr float VAT_BUDOWA = 8.f;
constexpr float VAT_KONSULTACJA = 23.f;
constexpr float PROMOCJA = 0.8;


struct Usluga {
    double cena;
    double vat;
};

int main()
{
    /* Create the render window and FRSGUI instance */
    const auto renderer_window_ptr = std::make_shared<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Logistyka", sf::Style::Default);
    fr::FRSGUI frsgui(renderer_window_ptr);

    /* Styles */
    auto text_style= Style("text", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::TEXT_COLOR, sf::Color::Black},
    }, frsgui);
    auto label_style= Style("label", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::CHARACTER_SIZE, 28},
    }, frsgui);
    auto input_style= Style("input", fr::ApplyBy::GROUP, 1, {
         {fr::KEY::SIZE, sf::Vector2f(300, 70)},
         {fr::KEY::BACKGROUND_COLOR, sf::Color::White},
         {fr::KEY::CHARACTER_SIZE, 48},
         {fr::KEY::OUTLINE_THICKNESS, 5.f},
         {fr::KEY::OUTLINE_COLOR, sf::Color(34, 35, 36)},
         {fr::KEY::TEXT_COLOR, sf::Color::Black}
    }, frsgui);
    auto checkbox_style = Style("checkbox", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::SIZE, sf::Vector2f(60, 60)},
        {fr::KEY::BACKGROUND_COLOR, sf::Color::White},
        {fr::KEY::OUTLINE_THICKNESS, 5.f},
        {fr::KEY::OUTLINE_COLOR, sf::Color(34, 35, 36)},
        {fr::KEY::SELECT_MARK_COLOR, sf::Color(34, 35, 36)}
    }, frsgui);
    auto btn_style = Style("btn", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::TEXT_COLOR, sf::Color::Black},
        {fr::KEY::SIZE, sf::Vector2f(150, 60)},
        {fr::KEY::CHARACTER_SIZE, 48},
        {fr::KEY::BACKGROUND_COLOR, sf::Color::White},
        {fr::KEY::OUTLINE_THICKNESS, 5.f},
        {fr::KEY::OUTLINE_COLOR, sf::Color(34, 35, 36)},
    }, frsgui);

    auto company_name_style= Style("header", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::CHARACTER_SIZE, 64},
        {fr::KEY::SIZE, sf::Vector2f(500, 100)},
        {fr::KEY::POSITION, sf::Vector2f(WINDOW_WIDTH/2 - 500/2, 10)}
    }, frsgui);
    auto client_data_style= Style("client_data", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::CHARACTER_SIZE, 48},
        {fr::KEY::SIZE, sf::Vector2f(300, 100)},
        {fr::KEY::POSITION, sf::Vector2f(50, 100)}
    }, frsgui);
    auto service_data_style= Style("service_data", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::CHARACTER_SIZE, 48},
        {fr::KEY::SIZE, sf::Vector2f(400, 100)},
        {fr::KEY::POSITION, sf::Vector2f(600, 100)}
    }, frsgui);

    auto company_name_label_style= Style("company_name_label", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::SIZE, sf::Vector2f(300, 30)},
        {fr::KEY::POSITION, sf::Vector2f(110, 200)}
    }, frsgui);
    auto company_name_input_style= Style("company_name_input", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::POSITION, sf::Vector2f(110, 250)}
    }, frsgui);

    auto workers_label_style= Style("workers_label", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::SIZE, sf::Vector2f(300, 30)},
        {fr::KEY::POSITION, sf::Vector2f(110, 340)}
    }, frsgui);
    auto workers_input_style= Style("workers_input", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::POSITION, sf::Vector2f(110, 380)}
    }, frsgui);

    auto distance_label_style= Style("distance_label", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::SIZE, sf::Vector2f(300, 30)},
        {fr::KEY::POSITION, sf::Vector2f(110, 480)}
    }, frsgui);
    auto distance_input_style= Style("distance_input", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::POSITION, sf::Vector2f(110, 520)}
    }, frsgui);

    auto consultation_label_style= Style("consultation_label", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::SIZE, sf::Vector2f(200, 30)},
        {fr::KEY::POSITION, sf::Vector2f(660, 300)}
    }, frsgui);
    auto consultation_box_style= Style("consultation_box", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::POSITION, sf::Vector2f(820, 280)}
    }, frsgui);

    auto build_label_style= Style("build_label", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::SIZE, sf::Vector2f(200, 30)},
        {fr::KEY::POSITION, sf::Vector2f(660, 400)}
    }, frsgui);
    auto build_box_style= Style("build_box", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::POSITION, sf::Vector2f(820, 380)}
    }, frsgui);

    auto result_style= Style("result", fr::ApplyBy::GROUP, 2, {
       {fr::KEY::POSITION, sf::Vector2f(660, 500)}
   }, frsgui);


    auto one_style= Style("one", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::SIZE, sf::Vector2f(200, 30)},
       {fr::KEY::POSITION, sf::Vector2f(860, 500)}
   }, frsgui);
    auto two_style= Style("two", fr::ApplyBy::GROUP, 2, {
            {fr::KEY::SIZE, sf::Vector2f(200, 30)},
       {fr::KEY::POSITION, sf::Vector2f(860, 560)}
   }, frsgui);
    auto tre_style= Style("tre", fr::ApplyBy::GROUP, 2, {
            {fr::KEY::SIZE, sf::Vector2f(200, 30)},
       {fr::KEY::POSITION, sf::Vector2f(860, 620)}
   }, frsgui);

    auto oneq_style= Style("oneq", fr::ApplyBy::GROUP, 2, {
        {fr::KEY::SIZE, sf::Vector2f(300, 30)},
       {fr::KEY::POSITION, sf::Vector2f(1060, 500)}
   }, frsgui);
    auto twoq_style= Style("twoq", fr::ApplyBy::GROUP, 2, {
            {fr::KEY::SIZE, sf::Vector2f(300, 30)},
       {fr::KEY::POSITION, sf::Vector2f(1060, 560)}
   }, frsgui);
    auto treq_style= Style("treq", fr::ApplyBy::GROUP, 2, {
            {fr::KEY::SIZE, sf::Vector2f(300, 30)},
       {fr::KEY::POSITION, sf::Vector2f(1060, 620)}
   }, frsgui);

    auto hid_style= Style("hid", fr::ApplyBy::GROUP, 10, {
        {fr::KEY::VISIBLE, false}
   }, frsgui);

    /* Header text | Company name */
    const auto header = fr::TextBlock::Builder(&frsgui)
    .setText("Wycena uslug")
    .addGroups({"text", "header"})
    .buildTextBlock();

    /* Left block | Dane firmy */
    const auto client_data = fr::TextBlock::Builder(&frsgui)
    .setText("Dane klienta")
    .addGroups({"text", "client_data"})
    .buildTextBlock();

    const auto company_name_label = fr::TextBlock::Builder(&frsgui)
    .setText("Nazwa firmy")
    .addGroups({"text", "label", "company_name_label"})
    .buildTextBlock();
    const auto company_name_input = fr::Input::Builder(&frsgui)
    .setID("company_name_input_id")
    .addGroups({"input", "company_name_input"})
    .isNumericalOnly(false)
    .buildInput();

    const auto workers_label = fr::TextBlock::Builder(&frsgui)
    .setText("Ilosc pracownikow")
    .addGroups({"text", "label", "workers_label"})
    .buildTextBlock();
    const auto workers_input = fr::Input::Builder(&frsgui)
    .setID("workers_input_id")
    .addGroups({"input", "workers_input"})
    .isNumericalOnly(true)
    .buildInput();

    const auto distance_label = fr::TextBlock::Builder(&frsgui)
    .setText("Odleglosc w km")
    .addGroups({"text", "label", "distance_label"})
    .buildTextBlock();
    const auto distance_input = fr::Input::Builder(&frsgui)
    .setID("distance_input_id")
    .addGroups({"input", "distance_input"})
    .isNumericalOnly(true)
    .buildInput();

    /* Middle block */
    const auto service_data = fr::TextBlock::Builder(&frsgui)
    .setText("Wybierz uslugi")
    .addGroups({"text", "service_data"})
    .buildTextBlock();

    const auto consultation_label = fr::TextBlock::Builder(&frsgui)
   .setText("Konsultacja")
   .addGroups({"text", "label", "consultation_label"})
   .buildTextBlock();
    const auto consultation_box = fr::Checkbox::Builder(&frsgui)
    .addGroups({"checkbox", "consultation_box"})
    .setID("consultation_box")
    .buildCheckbox();

    const auto build_label = fr::TextBlock::Builder(&frsgui)
   .setText("Budowa")
   .addGroups({"text", "label", "build_label"})
   .buildTextBlock();
   const auto build_box = fr::Checkbox::Builder(&frsgui)
   .addGroups({"checkbox", "build_box"})
    .setID("build_box")
   .buildCheckbox();

    const auto result = fr::Button::Builder(&frsgui)
    .addGroups({"btn", "result"})
    .setID("result")
    .setText("Oblicz")
    .buildButton();

    const auto one = fr::TextBlock::Builder(&frsgui)
    .setText("Koszt netto: ")
   .addGroups({"text", "label", "one", "hid"})
   .buildTextBlock();
    const auto two = fr::TextBlock::Builder(&frsgui)
    .setText("Kwota VAT: ")
   .addGroups({"text", "label", "two", "hid"})
   .buildTextBlock();
    const auto tre = fr::TextBlock::Builder(&frsgui)
    .setText("Koszt brutto: ")
   .addGroups({"text", "label", "tre", "hid"})
   .buildTextBlock();

    const auto oneq = fr::TextBlock::Builder(&frsgui)
   .addGroups({"text", "label", "oneq", "hid"})
   .buildTextBlock();
    const auto twoq = fr::TextBlock::Builder(&frsgui)
   .addGroups({"text", "label", "twoq", "hid"})
   .buildTextBlock();
    const auto treq = fr::TextBlock::Builder(&frsgui)
   .addGroups({"text", "label", "treq", "hid"})
   .buildTextBlock();


    result->setOnClick([&]()
    {
        std::string nazwaFirmy = frsgui.getInputByID("company_name_input_id")->getData();
        int pracownicy = frsgui.getInputByID("workers_input_id")->getDataAs<int>();;
        double odleglosc = frsgui.getInputByID("distance_input_id")->getDataAs<double>();;
        std::vector<Usluga> uslugi;

        bool konsultacja = frsgui.getCheckboxByID("consultation_box")->getSelect();
        bool budowa = frsgui.getCheckboxByID("build_box")->getSelect();

        if(konsultacja == true && budowa == true)
        {
            uslugi.push_back({CENA_KONSULTACJA * PROMOCJA, 23.0});
            uslugi.push_back({CENA_BUDOWA * PROMOCJA, 8.0});
        }
        else if(konsultacja == true)
        {
            uslugi.push_back({CENA_KONSULTACJA, 23.0});
        }
        else if(budowa == true)
        {
            uslugi.push_back({CENA_BUDOWA, 8.0});
        }

        double kosztNetto = 0.0, kwotaVAT = 0.0;

        for (const auto& usluga : uslugi) {
            kosztNetto += usluga.cena;
            kwotaVAT += usluga.cena * (usluga.vat / 100);
        }

        // Uwzględnianie liczby dni
        int liczbaDni = (pracownicy < 100) ? 1 : (pracownicy <= 200) ? 2 : 3;
        kosztNetto *= liczbaDni;
        kwotaVAT *= liczbaDni;

        // Koszt dojazdu
        double kosztDojazdu = odleglosc * CENA_ZA_KILOMETR;
        kosztNetto += kosztDojazdu;

        // Koszt logistyki
        if (odleglosc > 300.0) {
            double kosztLogistyki = 300.0 * liczbaDni;
            kosztNetto += kosztLogistyki;
        }

        double kosztBrutto = kosztNetto + kwotaVAT;

        oneq->setText(kosztNetto);
        twoq->setText(kwotaVAT);
        treq->setText(kosztBrutto);

        one->deleteGroup("hid");
        two->deleteGroup("hid");
        tre->deleteGroup("hid");
        oneq->deleteGroup("hid");
        twoq->deleteGroup("hid");
        treq->deleteGroup("hid");
    });

    while(renderer_window_ptr->isOpen())
    {
        sf::Event event{};
        while(renderer_window_ptr->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                renderer_window_ptr->close();
                break;
            }
            frsgui.dispatchEvent(event);
        }
        renderer_window_ptr->clear(sf::Color::White);

        // Render gui
        frsgui.Render();
        renderer_window_ptr->display();
    }
}
