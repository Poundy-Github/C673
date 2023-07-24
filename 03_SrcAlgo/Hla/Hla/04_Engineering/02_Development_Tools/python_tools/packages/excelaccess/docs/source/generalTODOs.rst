General TODOs
=============


Besprechung mit Matthias: (im Block ab 2.08.)
---------------------------------------------

*	Testen, ob immer dump oder ganz weglassen
*	XML-Template
*	Relative paths in xml nehmen
*	Header optional oder gar nicht ins xml machen
*	Cfg als Angabe in cmd obligatorisch annehmen 
	-	Xml (+ excelsheet + path ?)
*	Xml eher nach use-cases benennen
*	(HLA/)LSD -> Excel-Sheet
	-	Outputcheck generation auf ExcelAccess anpassen 
	-	Vorher nochmal mit Matthias abklaeren
*	Reader + Datenstruktur
*	"Overview" erstellen und digitalisieren 	
	-	mehr Beschreibungen
	-	Doku (HTML ; z.B. Sphinx)
*	Parameter reduzieren und fixer gestalten


Von mir: (im Block ab 8.08.)
----------------------------

*	Clear stuff
	-	Refactoring (PEP Standards)
	-	Adapting
	-	Removing 
	-	Fixing
	-	Documenting (add/update; update after finishing again)
	-	TODOs
	-	Parameters of classes/methods/functions
	-	Logging (einheitlich gestalten; messages anpassen)
*	More "try except" (e.g. all file interactions)
*	Implement special cases for headers?
*	Extend argparse for this project
*	Extract "features": mit Matthias besprechen
*	Tests schreiben
*	Check external documents (like word and python package list for this project)
*	Differentiate exceptions in more just one "block" (real handling)




15.08.17:
---------

*	Debugging/logging-levels configuration(?) e.g. "verbose" or something; graduating levels of logging in code
*	Make "unofficial" stuff "_private"
*	Refactor (table) content and header creation (nicht sehr uebersichtlich oder schoen)
	-	Teil-uebersicht machen? Und dann ueberlegen, was Sinn ergibt und implementieren
*	TODO-file in Projektverzeichnis (.txt)
*	"Module Content" in HTML? Raus oder iwas rein machen?
*	Eclipse Plugin zum Erstellen von Diagrammen/Schaubildern? 
	-	Z.B. dann pro Modul oder so
*	Feature-Struktur ueberlegen (wie modularisieren; Schnittstellen? Etc.)


16.08.17:
---------


Dokumentation:

*	private methods/classes etc.; add documentation script to configure updates to documentation
	-	private classes are ignored until now
*	Adapt documentation rtypes and vartypes
*	konsistente Beschreibungen
*	Add nice package docs in __init__.py (?)
*	Docs: add PEP; integrate some links/pages?
*	Aufrufstruktur der Skripte ueberlegen
*	Styling aendern
*	More comments
*	Testcases abdecken mit extra Excel file etc. und Testing framework (Tests schreiben)
*	Dokumentation
	-	Automatische Aktualisierung der Doku: extra Skript anlegen, das das tut
*	add overview diagrams to docs?


Refactoring:

*	Redundanzen/hardcoding und sowas entfernen
	-	Altes Zeug entfernen, das man nicht mehr braucht
	-	Utility functions etc. zentral fuer bessere uebersichtlichkeit und Importierbarkeit
*	PEP8 ansehen
	-	"besseres" Python schreiben
	-	Exports
	-	Leading underscores fuer non public stuff
*	Refactoring/Optimierung am Ende
	-	Checks adden, falls fehlend
	-	Arguments verbessern, falls schlecht/falsch (mutable?)
*	XML: 
	-	table parameters/attributes: remove/change table_id?
*	Problems:
	- indices for tables: data and header, if there was a blank cell which is ignored
		+ testing for such stuff 
		+ find fix afterwards and keep tests up-to-date


Improvements:

*	Leere Spalten in Header "fehlen" ...idx adden? (also z.B. einfach reihen-/spalten-index)
*	Merged cells effizienter gestalten (eventuell ueber dict pro zeile/spalte oder so)
	-	Consumer functions? (siehe Block, fuer Header etc.)
*	Special cases abdecken, z.B. Tabellen-Header-Formate?
	-	Special lines etc.
	-	Divider in Tabellen "ausklammern"


Features:

*	Suche:
	-	Regex (basics wie int, float, ... gleich bereitstellen?)
	-	Text
*	Parsing:
	-	Auto-find von Headern/Tabellen/ ...
*	Visualisierung:
	-	Plotting (extra Package?) z.B. ueber Pandas
*	User input options (siehe Python, config package)
*	Access auch ueber normales xlrd noch moeglich machen! (also dass man einfach die normale lib nutzen kann) (oder auf xlrd mit openpyxl support ummuenzen?)
*	Features an-/abwaehlbar fuer Senkung der Komplexitaet je nach Anspruch
	-	Z.B. keine dumps, nur banales lesen oder so
*	Automatische Verarbeitung von neuen und alten Excel-Files
	-	Speichern aber dann noch ueberlegen, wie das klappen kann
*	Cell-Groups lesen oder nur Teile von Tabellen (in xml z.B. festlegen)
	-	Sachen in Groups zerlegen?
*	Aggregation von columns oder so zu key, um dann Sachen zu suchen(wie in dem Skript fuer ResSheet)
*	Multi-/Crossreference innerhalb von Dateien und ueber Dateien hinweg 
	-	Kombi-betrieb, zusammensetzen
	-	Algorithmische Herangehensweise? Besser als das Skript mit den Hashs und Intersections von Index-Listen?
*	Defaults fuer verschiedene Features
	-	Table styles
	-	Header styles
	-	Formatting (z.B. fuer outputs)
	-	Einfach nur Zellen lesen, ...etc.
*	Andere Features, je nach Nutzungsgrad der Datei
	-	Haeufige Veraenderung der Datei:
		+	Big overhead, weil jedes Mal alles aktualisiert werden muss
		+	Also einfach das auch auswaehlbar machen oder so?
		+	Eventuell in Doku einbringen
*	Genereller Output-Generator? (also banale Optionen wie outputten)
* 	active key-value naming (e.g. table_id as real id and dict in code)


Ziele:

*	Klassen generalisieren bzw. den Zugriff auf Excel
	-	Alte Skripte daran anpassen
	-	Packagen und in Tools ablegen
*	Logging/Errorhandling
*	API-like usage -> wrapper schreiben etc.


Ideen:

*	Search-Trees oder andere Strukturen suchen und nutzen?
*	Pro Job/File Verzeichnis anlegen und da dumps, xmls etc. speichern
	-	Verzeichnisstruktur und Dateistruktur ueberdenken?
*	Per-table search dicts, global search dicts, inter-ref-search dicts, ...
	-	Special dumps, sql, ...
	-	Dumps pro sheet, pro table, pro file, pro job, ...
*	Merged_cells and stuff nach rows/cols ordnen
	-	Spaeter besser zu verwenden?
	-	Extra infos sinnvoll, die man vorberechnen koennte?
*	Mehrere excel files pro "job" moeglich? (xml root muesste man dann z.B. anpassen)
	-	Anhand dessen dann auch dumps suchen/laden?
	-	In config die dumps unterbringen?
	-	In config features unterbringen? 
		+	Config-Tags auch anderweitig verwenden? 
*	Relative/absolute Zeilen/Spalten (je nachdem dann offsets verwenden) bei Indizierung in Tabellen bei der Suche z.B.
*	Kwargs featured functions/methods
*	ueberlegen ob irgendwie doch automatische Tabellenerkennung moeglich ist?
	-	Oder defaults fuer sheets (in configs z.B. pro sheet einen Standard festlegen fuer header rows, table look etc.)
*	Blaue Kaesten in Block noch aufnehmen/beachten

	
Fragen:

*	Wie Zeug handlen, das keine (ueblichen) Tabellen sind? Spezielle Zeilen, freier Text..., dafuer extra Tags anlegen und iwie indizierte Speichermoeglichkeit (Dictionary) in der Datenstruktur anlegen?
*	Multi-File reading unterstuetzen?
*	Verschiedene Formate spaeter durch neue Packages ergaenzen?


