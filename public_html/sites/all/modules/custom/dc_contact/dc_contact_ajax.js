(function ($) {
    Drupal.ajax.prototype.commands.dc_contact_reset_form = function (ajax, response, status) {
        jQuery('#dc-contact-form')[0].reset();
        $('#messages').remove();
    };

    Drupal.ajax.prototype.commands.dc_contact_add_errors_block = function (ajax, response, status) {
        $('#messages').remove();

        var messagesBlock = '<div id="messages"><div class="section clearfix"><div class="messages error"><h2 class="element-invisible">Error message</h2><ul id="errors"></ul></div></div></div>';
        $(messagesBlock).insertAfter($('#header'));

        $.each(response.errors, function (index, element) {
            $('#errors').append('<li>' + element + '</li>');
        });
    };
}(jQuery));
