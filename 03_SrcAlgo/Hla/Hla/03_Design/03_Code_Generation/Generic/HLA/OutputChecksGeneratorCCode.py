import sys
import os

from abc import ABCMeta, abstractmethod

# extend path so imports can be found; suppression needed because IDE (PyCharm) does not have the correct scope and
# complains about unresolved imports
sys.path.extend([os.path.abspath(r".\..\ExcelAccess")])
# noinspection PyUnresolvedReferences
from excelaccess.utils.general_functions import is_sequence


# [] indicate indentation structure
# add comments + documentation
# TODO: adapt composer with flush feature or something, to use it more static with less instances?
# TODO: add logger at some spots, e.g. zipping at switchcase; add docstrings and comments as classes or something?
class OutputBlockComposer:
    """Simply creates output strings for provided OutputBlocks.

    :param str indentation_step: how much should one step indent (defaults to two spaces)
    :param str base_indentation: base indentation (defaults to empty string)
    """

    def __init__(self, indentation_step=None, base_indentation=None):
        self.ind_step = indentation_step if indentation_step else " " * 2
        self.indentation = ""
        self.base_indentation = base_indentation if base_indentation else ""

        self.output_list = []

    def add_block(self, block):
        """Add a new output block.

        :param BaseBlock block: block to be added
        """
        self.output_list.extend(block.get_block())

    def get_output(self, _items=None, _indentation=0):
        """

        :param _items: items for recursion
        :param int _indentation: computed indentation for recursion
        :return: output string of output list
        :rtype str
        """
        if _items is None:
            _items = self.output_list

        out_str = ""

        for item in _items:
            if is_sequence(item):
                out_str += self.get_output(item, _indentation + 1)
            else:
                out_str += "{indentation}{item}\n".format(
                    indentation=self.base_indentation + (self.ind_step * _indentation),
                    item=item)
        return out_str


def _add_item(target_list, item):
    """Add an item to a target list.

    :param target_list: list to receive item
    :type target_list: list
    :param item: item to be added
    """
    if is_sequence(item):
        target_list.extend(item)
    else:
        target_list.append(item)


def _compose_list(target_list, source_list):
    """Adds a source list to a target list.

    :param target_list: list to receive items
    :type target_list: list
    :param source_list: list to provide items
    :type source_list: list
    """
    source_list = source_list if is_sequence(source_list) else [source_list]
    for item in source_list:
        if isinstance(item, BaseBlock):
            # item is (sub)class of BaseBlock providing content over get_block()-method
            # get_block()-method returns a list on same indentation level as target list, so has to extend target list
            target_list.extend(item.get_block())
        else:
            # single item or list which has to be appended to preserve correct indentation
            target_list.append(item)


# TODO: add comments etc. as classes?
class BaseBlock:
    """Base class for block oriented output classes."""
    __metaclass__ = ABCMeta

    def __init__(self):
        self._output_block = []
        self._preamble = []
        self._head = []
        self._body_frame = []
        self._upper_body = []
        self._main_body = []
        self._lower_body = []
        self._tail = []

    def _add_preamble(self, preamble):
        """Preamble represents stuff to be placed at the start of a block. (e.g. comments, docstrings, ...)

        :param preamble:
        :type preamble: str or BaseBlock
        """
        _add_item(self._preamble, preamble)

    def _compose_preamble(self):
        """Composes elements for the preamble. Defaults to just adding the preamble list to the output block list."""
        _compose_list(self._output_block, self._preamble)

    def _add_head(self, head):
        """Adds new item to head. Head represents the logical frame, e.g. the declaration part of a function.

        :param head: item to be added
        """
        _add_item(self._head, head)

    def _compose_head(self):
        """Composes elements for the head. Defaults to just adding the head list to the output block list."""
        _compose_list(self._output_block, self._head)

    def _add_upper_body(self, body):
        """Adds new item to upper body. Body represents e.g. the function body and for convenience is divided into
        upper, main and lower body. Upper body takes stuff which should come at the start of the body, lower body takes
        stuff which should come at the end and main body takes stuff for in between.

        :param body: item to be added
        :type body: str or BaseBlock
        """
        _add_item(self._upper_body, body)

    def _compose_upper_body(self):
        """Composes elements for the upper body. Defaults to just adding the upper body list to the body frame list."""
        _compose_list(self._body_frame, self._upper_body)

    def _add_main_body(self, body):
        """Adds new item to upper body. Body represents e.g. the function body and for convenience is divided into
        upper, main and lower body. Upper body takes stuff which should come at the start of the body, lower body takes
        stuff which should come at the end and main body takes stuff for in between.

        :param body:
        :type body: str or BaseBlock
        """
        _add_item(self._main_body, body)

    def _compose_main_body(self):
        """Composes elements for the main body. Defaults to just adding the main body list to the body frame list."""
        _compose_list(self._body_frame, self._main_body)

    def _add_lower_body(self, body):
        """Adds new item to upper body. Body represents e.g. the function body and for convenience is divided into
        upper, main and lower body. Upper body takes stuff which should come at the start of the body, lower body takes
        stuff which should come at the end and main body takes stuff for in between.

        :param body: item to be added
        :type body: str or BaseBlock
        """
        _add_item(self._lower_body, body)

    def _compose_lower_body(self):
        """Composes elements for the lower body. Defaults to just adding the lower body list to the body frame list."""
        _compose_list(self._body_frame, self._lower_body)

    def _compose_body_frame(self):
        """Composes elements for the whole body called body frame. Defaults to just adding the body frame list to the
        output block list."""
        self._compose_upper_body()
        self._compose_main_body()
        self._compose_lower_body()
        self._output_block.append(self._body_frame)

    def _add_tail(self, tail):
        """Adds new item to tail. Tail represents stuff that should go after the body, e.g. closing brackets can be
        added here or in the lower body.

        :param tail:
        :type tail: str or BaseBlock
        """
        _add_item(self._tail, tail)

    def _compose_tail(self):
        """Composes elements for the tail. Defaults to just adding the tail list to the output block list."""
        _compose_list(self._output_block, self._tail)

    def get_direct_output(self):
        """Returns a direct string representation of this block.

        :return: block representation
        :rtype str
        """
        output_composer = OutputBlockComposer()
        output_composer.add_block(self)
        return output_composer.get_output()

    @abstractmethod
    def get_block(self):
        """Calls all compose methods. Intention is to provide kind of late evaluation, so one is able to add new items
        until he calls the get_block()-method of a BaseBlock.

        :return: output block list
        :rtype list(str)
        """
        # start
        self._compose_preamble()
        self._compose_head()

        # body frame
        self._compose_body_frame()

        # end
        self._compose_tail()

        return self._output_block


class ForLoop(BaseBlock):
    """BaseBlock representation of a C code for loop.

    :param str end_value: end value of for loop
    :param str start_value: start value of for loop (defaults to '0')
    :param str index_var: index variable of for loop (defaults to 'i')
    :param str equality: equality to be used (defaults to '<')
    :param bool down: loop direction (defaults to '++')
    """
    loop_head_template = "for({index_var} = {start_value}; {index_var} {equality} {end_value}; {index_var}{direction})"

    def __init__(self, end_value, start_value=None, index_var=None, equality=None, down=False):
        super(ForLoop, self).__init__()
        self._end_value = end_value
        self._start_value = start_value if start_value else "0u"
        self._index_var = index_var if index_var else "i"
        self._equality = equality if equality else "<"
        self._direction = "--" if down else "++"

    def _add_loop_start(self):
        """'Header method' of this subclass. Composes and adds a for loop header."""
        self._add_head(
            self.loop_head_template.format(
                index_var=self._index_var, start_value=self._start_value, equality=self._equality,
                end_value=self._end_value,
                direction=self._direction))

    def get_block(self):
        self._add_loop_start()
        return super(ForLoop, self).get_block()

    def add_tail(self, tail):
        super(ForLoop, self)._add_tail(tail)

    def add_preamble(self, preamble):
        super(ForLoop, self)._add_preamble(preamble)

    def add_main_body(self, body):
        super(ForLoop, self)._add_main_body(body)

    def _compose_tail(self):
        super(ForLoop, self)._compose_tail()
        self._output_block.append("}\n")

    def add_lower_body(self, body):
        super(ForLoop, self)._add_lower_body(body)

    def _compose_upper_body(self):
        self._output_block.append("{")
        super(ForLoop, self)._compose_upper_body()

    def add_upper_body(self, body):
        super(ForLoop, self)._add_upper_body(body)

    def get_direct_output(self):
        return super(ForLoop, self).get_direct_output()


class Function(BaseBlock):
    function_declaration_template = "static void {prefix}{fn_name}({parameters})"

    def __init__(self, function_name=None):
        super(Function, self).__init__()
        self._head = function_name
        self._function_prefixes = []
        self._function_parameters = []

    def add_preamble(self, preamble):
        super(Function, self)._add_preamble(preamble)

    def set_function_name(self, function_name):
        """

        :param function_name:
        """
        self._head = function_name

    def add_function_prefix(self, function_prefix):
        """

        :param function_prefix:
        """
        self._function_prefixes.append(function_prefix)

    def _compose_prefixes(self):
        """

        :return:
        """
        return "".join(self._function_prefixes)

    def add_function_parameter(self, function_parameter):
        """

        :param function_parameter:
        :return:
        """
        self._function_parameters.append(function_parameter)

    def _compose_function_parameters(self):
        """

        :return:
        """
        if self._function_parameters:
            return " ".join(self._function_parameters)
        return ""

    def _compose_head(self):
        self._output_block.append(self.function_declaration_template.format(prefix=self._compose_prefixes(),
                                                                            fn_name=self._head,
                                                                            parameters=self._compose_function_parameters()))
        self._output_block.append("{")

    def add_main_body(self, body):
        super(Function, self)._add_main_body(body)

    def add_upper_body(self, body):
        super(Function, self)._add_upper_body(body)

    def add_lower_body(self, body):
        super(Function, self)._add_lower_body(body)

    def add_tail(self, tail):
        super(Function, self)._add_tail(tail)

    def _compose_tail(self):
        super(Function, self)._compose_tail()
        self._output_block.append("}\n")

    def get_block(self):
        return super(Function, self).get_block()


# TODO: make extra classes for if, then, else and else if?
class IfThenElse(BaseBlock):
    leading_space = " "
    leading_and = "&&"
    leading_or = "||"
    leading_template = " {0} "

    def __init__(self, conditions=None, body=None):
        super(IfThenElse, self).__init__()
        self._conditions = conditions if is_sequence(conditions) else [conditions]
        if body:
            self._main_body = body if is_sequence(body) else [body]
        self._conditions_block = []

    def _add_conditions(self):
        multiple_conditions = len(self._conditions) > 1
        for condition in self._conditions:
            first = condition == self._conditions[0]
            last = condition == self._conditions[-1]
            if condition == self._conditions[0] and multiple_conditions:
                self._add_condition(condition, self.leading_template.format(self.leading_space), start=first, end=last)
            elif multiple_conditions:
                self._add_condition(condition, self.leading_template.format(self.leading_and), start=first, end=last)
            else:
                self._add_condition(condition, "", start=first, end=last)

    def _add_condition(self, condition, leading=None, start=False, end=False):
        if start and end:
            template = "if({0}({1}))" if leading else "if({0}{1})"
            self._output_block.append(template.format(leading, condition))
        elif start:
            template = "if({0}({1})" if leading else "if({0}{1}"
            self._output_block.append(template.format(leading, condition))
        else:
            template = "{0}({1})" if leading else "{0}{1}"
            self._output_block.append([template.format(leading, condition)])
        if end and not start:
            self._output_block.append([")"])

    def set_conditions(self, conditions):
        self._conditions = conditions if is_sequence(conditions) else [conditions]

    def _compose_upper_body(self):
        self._output_block.append("{")
        super(IfThenElse, self)._compose_upper_body()

    def _compose_tail(self):
        super(IfThenElse, self)._compose_tail()
        self._output_block.append("}\n")

    def get_block(self):
        # start
        self._compose_preamble()
        self._add_conditions()
        self._compose_head()

        # body frame
        self._compose_body_frame()

        # end
        self._compose_tail()

        return self._output_block

    def add_preamble(self, preamble):
        """Preamble represents stuff to be placed at the start of a block. (e.g. comments, docstrings, ...)"""
        super(IfThenElse, self)._add_preamble(preamble)

    def add_upper_body(self, body):
        super(IfThenElse, self)._add_upper_body(body)

    def add_main_body(self, body):
        super(IfThenElse, self)._add_main_body(body)

    def add_lower_body(self, body):
        super(IfThenElse, self)._add_lower_body(body)

    def add_tail(self, tail):
        super(IfThenElse, self)._add_tail(tail)


class SwitchCase(BaseBlock):
    def __init__(self, switch=None, reference=None, values=None, default_action=None, actions=None):
        super(SwitchCase, self).__init__()
        self._switch = switch
        self._reference = reference
        self._default_action = default_action if is_sequence(default_action) else [default_action]
        self._cases = []
        if values:
            self._values = values if is_sequence(values) else [values]
        else:
            self._values = []
        if actions:
            self._actions = actions if is_sequence(actions) else [actions]
        else:
            self._actions = []

    def _compose_head(self):
        self._output_block.append("switch({switch})".format(switch=self._switch))
        self._output_block.append("{")

    def _add_case_statement(self, value, action=None, last=False):
        _add_item(self._cases, _Case(value, self._reference, action, last))

    def _add_default_statement(self, action=None):
        _add_item(self._cases, _Default(action))

    def set_switch(self, switch):
        self._switch = switch

    def add_value(self, value):
        _add_item(self._values, value)

    def add_default_action(self, default_action):
        _add_item(self._default_action, default_action)

    def add_case_action(self, action):
        _add_item(self._actions, action)

    def _compose_cases(self):
        if self._actions:
            values = zip(self._values, self._actions)
            for value, action in values:
                self._add_case_statement(value, action, (value == self._values[-1]))
        else:
            for value in self._values:
                self._add_case_statement(value, last=(value == self._values[-1]))
        self._add_default_statement(self._default_action)
        _compose_list(self._output_block, self._cases)

    def get_block(self):
        self._compose_head()
        self._compose_cases()
        self._output_block.append("}\n")
        return self._output_block


class _Case(BaseBlock):
    """SwitchCase helper class for case statements.

    :param case: the case check
    :param actions: actions to be executed in this case statement
    :type actions: None, str, BaseBlock or list
    :param bool set_break: if a break should be set at the end of this case statement
    """
    case_template = "case ({cast}){case}:"

    def __init__(self, case, reference, actions=None, set_break=False):
        super(_Case, self).__init__()
        self._case = case
        self._reference =reference
        if actions:
            self._actions = actions if is_sequence(actions) else [actions]
        else:
            self._actions = []
        self._set_break = set_break

    def _compose_head(self):
        self._output_block.append(self.case_template.format(cast=self._reference, case=self._case))

    def add_action(self, action):
        """Adds a action for the body of this case statement. Actions are e.g. code lines in C code.

        :param action: action to be added
        :type action: str or BaseBlock
        """
        _add_item(self._actions, action)

    def _compose_actions(self):
        """Composes all actions and adds them to the output block list. Adds 'break' if set True."""
        if self._set_break:
            self._actions.append("break;")
        self._output_block.append(self._actions)

    def get_block(self):
        self._compose_head()
        self._compose_actions()
        return self._output_block


class _Default(BaseBlock):
    """SwitchCase helper class for default statements.

    :param actions: actions to be executed in this default statement
    :type actions: None, str, BaseBlock or list
    """

    def __init__(self, actions=None):
        super(_Default, self).__init__()
        if actions:
            self._actions = actions if is_sequence(actions) else [actions]
        else:
            self._actions = []

    def _compose_head(self):
        self._output_block.append("default:")

    def add_action(self, action):
        """Adds a action for the body of this case statement. Actions are e.g. code lines in C code.

        :param action: action to be added
        :type action: str or BaseBlock
        """
        _add_item(self._actions, action)

    def _compose_actions(self):
        """Composes all actions and adds them to the output block list. Adds 'break' if set True."""
        self._actions.append("break;")
        self._output_block.append(self._actions)

    def get_block(self):
        self._compose_head()
        self._compose_actions()
        return self._output_block
