# $Id: af.py 1.1 2018/03/15 10:31:52CET Mutschler, Matthias (uidv7867) none  $
# Author: Jannie Hofmeyr <jhsh@sun.ac.za>
# Copyright: This module has been placed in the public domain.

# New language mappings are welcome.  Before doing a new translation, please
# read <http://docutils.sf.net/docs/howto/i18n.html>.  Two files must be
# translated for each language: one in docutils/languages, the other in
# docutils/parsers/rst/languages.

"""
Afrikaans-language mappings for language-dependent features of
reStructuredText.
"""

__docformat__ = 'reStructuredText'


directives = {
      'aandag': 'attention',
      'versigtig': 'caution',
      'code (translation required)': 'code',
      'gevaar': 'danger',
      'fout': 'error',
      'wenk': 'hint',
      'belangrik': 'important',
      'nota': 'note',
      'tip': 'tip', # hint and tip both have the same translation: wenk
      'waarskuwing': 'warning',
      'vermaning': 'admonition',
      'kantstreep': 'sidebar',
      'onderwerp': 'topic',
      'lynblok': 'line-block',
      'math (translation required)': 'math',
      'parsed-literal (translation required)': 'parsed-literal',
      'rubriek': 'rubric',
      'epigraaf': 'epigraph',
      'hoogtepunte': 'highlights',
      'pull-quote (translation required)': 'pull-quote',
      u'compound (translation required)': 'compound',
      u'container (translation required)': 'container',
      #'vrae': 'questions',
      #'qa': 'questions',
      #'faq': 'questions',
      'table (translation required)': 'table',
      'csv-table (translation required)': 'csv-table',
      'list-table (translation required)': 'list-table',
      'meta': 'meta',
      #'beeldkaart': 'imagemap',
      'beeld': 'image',
      'figuur': 'figure',
      'insluiting': 'include',
      'rou': 'raw',
      'vervang': 'replace',
      'unicode': 'unicode', # should this be translated? unikode
      'datum': 'date',
      'klas': 'class',
      'role (translation required)': 'role',
      'default-role (translation required)': 'default-role',
      'title (translation required)': 'title',
      'inhoud': 'contents',
      'sectnum': 'sectnum',
      'section-numbering': 'sectnum',
      u'header (translation required)': 'header',
      u'footer (translation required)': 'footer',
      #'voetnote': 'footnotes',
      #'aanhalings': 'citations',
      'teikennotas': 'target-notes',
      'restructuredtext-test-directive': 'restructuredtext-test-directive'}
"""Afrikaans name to registered (in directives/__init__.py) directive name
mapping."""

roles = {
    'afkorting': 'abbreviation',
    'ab': 'abbreviation',
    'akroniem': 'acronym',
    'ac': 'acronym',
    u'code (translation required)': 'code',
    'indeks': 'index',
    'i': 'index',
    'voetskrif': 'subscript',
    'sub': 'subscript',
    'boskrif': 'superscript',
    'sup': 'superscript',
    'titelverwysing': 'title-reference',
    'titel': 'title-reference',
    't': 'title-reference',
    'pep-verwysing': 'pep-reference',
    'pep': 'pep-reference',
    'rfc-verwysing': 'rfc-reference',
    'rfc': 'rfc-reference',
    'nadruk': 'emphasis',
    'sterk': 'strong',
    'literal (translation required)': 'literal',
    'math (translation required)': 'math',
    'benoemde verwysing': 'named-reference',
    'anonieme verwysing': 'anonymous-reference',
    'voetnootverwysing': 'footnote-reference',
    'aanhalingverwysing': 'citation-reference',
    'vervangingsverwysing': 'substitution-reference',
    'teiken': 'target',
    'uri-verwysing': 'uri-reference',
    'uri': 'uri-reference',
    'url': 'uri-reference',
    'rou': 'raw',}
"""Mapping of Afrikaans role names to canonical role names for interpreted text.
"""
